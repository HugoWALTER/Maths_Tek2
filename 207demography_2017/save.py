#!/usr/bin/env python3

import  sys
import  re
from math import *

def             check_file():
    try:
        fd = open("207demography_data.csv", "r")
    except:
        print("Error: The file can't be opened !")
        exit(84)
    return (fd)

def             open_and_parse_file(ac, av):
    fd = check_file()
    i = 1
    liste = []
    flag = 0
    res = 0

    while (i < ac):
        fd.seek(0)
        flag = 0
        for line in fd.readlines():
            res = re.sub(",", ".", line)
            res = res.split(";")
            if (av[i] == res[1]):
                flag = 1
                liste.append(res)
        if (flag == 0):
            print("Error: The or one of the flag doesn't exist!")
            exit(84)
        i += 1
    if (not liste):
        print("Error: The flag doesn't exist !")
        exit(84)
    return (liste)

def             display_country(liste):
    i = 0
    len_list = len(liste)

    print("country:", end='')
    while (i < len_list):
        if (i == 0):
            print("", liste[i][0], end='')
        else:
            print(",", liste[i][0], end='')
        i += 1
    print("")

def             verif_country(new_list):
    i = 0
    value = 0
    while (i <= 50):
        value += new_list[i]
        i += 1
    if (value == 0):
        print("Error: All values equals to 0")
        exit(84)

def             update_list_with_country(liste):
    new_list = []
    i = 2
    len_list = len(liste)
    get_year = 0

    while (i <= 52):
        get_year = 0
        j = 0
        while (j < len_list):
            try:
                if liste[j][i] != "":
                    get_year += float(liste[j][i])
            except:
                get_year += 0
            j += 1
        new_list.append(get_year)
        i += 1
    verif_country(new_list)
    return (new_list)

def             calc_fit1(liste):
    i = 0
    min_year = 1961
    fill_year = []
    fill_pop = []
    moy_year = 0
    moy_pop = 0
    num_equation_ax = 0
    denum_equation_ax = 0

    while (min_year <= 2011):
        fill_year.append(min_year)
        fill_pop.append(float(liste[i]) / pow(10, 6))
        num_equation_ax += min_year * (float(liste[i]) / pow(10, 6))
        denum_equation_ax += pow(min_year, 2)
        moy_year += min_year
        moy_pop += float(liste[i]) / pow(10,6)
        min_year += 1
        i += 1
    moy_year /= len(liste)
    moy_pop /= len(liste)
    num_equation_ax -= len(liste) * moy_year * moy_pop
    denum_equation_ax -= len(liste) * pow(moy_year, 2)
    return moy_year, moy_pop, num_equation_ax, denum_equation_ax, fill_year, fill_pop

def             equation_fit1(liste, moy_year, moy_pop, num_equation_ax, denum_equation_ax):
    i = 0
    min_year = 1961
    ax = 0
    ay = 0
    bx = 0
    by = 0
    num_equation_ay = 0
    denum_equation_ay = 0

    while (min_year <= 2011):
        num_equation_ay += (min_year - moy_year) * ((float(liste[i]) / pow(10, 6)) - moy_pop)
        denum_equation_ay += pow(((float(liste[i]) / pow(10, 6)) - moy_pop), 2)
        min_year += 1
        i += 1
    ax = num_equation_ax / denum_equation_ax
    bx = moy_pop - ax * moy_year
    ay = num_equation_ay / denum_equation_ay
    by = moy_year - ay * moy_pop
    return num_equation_ay, denum_equation_ay, moy_year, moy_pop, ax, bx, ay, by

def             calc_fit2(ax, bx, ay, by):
    i = 0
    min_year = 1961
    fit1_pop_2050 = []
    fit2_pop_2050 = []
    res_fit1 = 0
    res_fit2 = 0

    while (min_year <= 2050):
        res_fit1 = ax * min_year + bx
        res_fit2 = (min_year - by) / ay
        fit1_pop_2050.append(res_fit1)
        fit2_pop_2050.append(res_fit2)
        min_year += 1
        i += 1
    return ax, bx, ay, by, fit1_pop_2050, fit2_pop_2050

def             calc_sd_fit1(liste, ax, bx):
    i = 0
    min_year = 1961
    ecart_tmp = 0
    tmp = 0
    sd_fit1 = 0

    while (min_year <= 2011):
        tmp = (float(liste[i]) / pow(10, 6)) - (ax * min_year + bx)
        ecart_tmp += pow(tmp, 2)
        min_year += 1
        i += 1
    sd_fit1 = sqrt(ecart_tmp / i)
    return sd_fit1

def             calc_sd_fit2(liste, ay, by):
    i = 0
    min_year = 1961
    ecart_tmp = 0
    sd_fit2 = 0
    tmp = 0

    while (min_year <= 2011):
        tmp = (float(liste[i]) / pow(10, 6)) - ((min_year - by) / ay)
        ecart_tmp += pow(tmp, 2)
        min_year += 1
        i += 1
    sd_fit2 = sqrt((ecart_tmp / (i)))
    return sd_fit2

def             calc_list_by_year(liste):
    correlation = 0

    moy_year, moy_pop, num_equation_ax, denum_equation_ax, listYear, listPop = calc_fit1(liste)
    num_equation_ay, denum_equation_ay, moy_year, moy_pop, ax, bx, ay, by = equation_fit1(liste, moy_year, moy_pop, num_equation_ax, denum_equation_ax)
    ax, bx, ay, by, fit1_pop_2050, fit2_pop_2050 = calc_fit2(ax, bx, ay, by)
    sd_fit1 = calc_sd_fit1(liste, ax, bx)
    sd_fit2 = calc_sd_fit2(liste, ay, by)
    correlation = sqrt(ax * ay)

    display_res(ax, ay, bx, by, sd_fit1, sd_fit2, fit1_pop_2050, fit2_pop_2050, correlation)

def     display_fit1(ax, bx, sd_fit1, fit1_pop_2050):
    print("fit 1")
    if (bx > 0):
        print("\tY = %.2f X + %.2f" %(ax, bx))
    else:
        print("\tY = %.2f X - %.2f" %(ax, abs(bx)))
    print("\tstandard deviation:\t%.2f" %sd_fit1)
    print("\tpopulation in 2050:\t%.2f" %float(fit1_pop_2050[89]))

def     display_fit2(ax, ay, by, sd_fit2, fit2_pop_2050):
    print("fit 2")
    if (by > 0):
        print("\tY = %.2f X + %.2f" %(ay, by))
    else:
        print("\tY = %.2f X - %.2f" %(ay, abs(by)))
    print("\tstandard deviation:\t%.2f" %sd_fit2)
    print("\tpopulation in 2050:\t%.2f" %float(fit2_pop_2050[89]))

def     display_correlation(correlation):
    print("correlation:\t%.4f" %correlation)

def     display_res(ax, ay, bx, by, sd_fit1, sd_fit2, fit1_pop_2050, fit2_pop_2050, correlation):
    display_fit1(ax, bx, sd_fit1, fit1_pop_2050)
    display_fit2(ax, ay, by, sd_fit2, fit2_pop_2050)
    display_correlation(correlation)

if (len(sys.argv) == 1):
    print("Error: Please use at least one argument (see -h)")
    exit(84)
if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
    print("USAGE\n\t./207demography code1 [...]\nDESCRIPTION\n\tcode1\tcountry code")
    exit(84)
if (len(sys.argv) == 2 or len(sys.argv) > 2):
    liste = 0

    liste = open_and_parse_file(len(sys.argv), sys.argv)
    display_country(liste)
    liste = update_list_with_country(liste)
    calc_list_by_year(liste)
exit(0)
