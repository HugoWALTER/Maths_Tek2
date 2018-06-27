/*
** EPITECH PROJECT, 2018
** 201yams
** File description:
** 201yams C
*/

#include "my.h"

int	intcmp(int *tab, t_mapsize *val, int size)
{
	int wani = 0;
	int biyu = 0;
	int uku = 0;
	int hudu = 0;
	int biyar = 0;
	int shida = 0;
	int i = 0;

	if (size == 5)
	{
		while (tab[i])
		{
			if (tab[i] == 1 && wani == 0)
				wani++;
			if (tab[i] == 2 && biyu == 0)
				biyu++;
			if (tab[i] == 3 && uku == 0)
				uku++;
			if (tab[i] == 4 && hudu == 0)
				hudu++;
			if (tab[i] == 5 && biyar == 0)
				biyar++;
			i++;
		}
		return (biyu + uku + hudu + biyar + wani);
	}
	if (size == 6)
	{
		while (tab[i])
		{
			if (tab[i] == 2 && biyu == 0)
				biyu++;
			if (tab[i] == 3 && uku == 0)
				uku++;
			if (tab[i] == 4 && hudu == 0)
				hudu++;
			if (tab[i] == 5 && biyar == 0)
				biyar++;
			if (tab[i] == 6 && shida == 0)
				shida++;
			i++;
		}
		return (biyu + uku + hudu + biyar + shida);
	}
}

int	usage(void)
{
	printf("./201yams -h\nUSAGE\n\t./201yams d1 d2 d3 d4 d5 c\n\nDESCRIPTION\n\td1\tvalue of the first die (0 if not thrown)\n\td2\tvalue of the second die (0 if not thrown)\n\td3\tvalue of the third die (0 if not thrown)\n\td4\tvalue of the fourth die (0 if not thrown)\n\td5\tvalue of the fifth die (0 if not thrown)\n\tc\texpected combination\n");
	exit (0);
}

int	init_struct(t_mapsize **val)
{
  t_mapsize	*lm;

  if ((lm = malloc(sizeof(*lm))) == NULL)
	  return (84);
  lm->de1 = 0;
  lm->de2 = 0;
  lm->de3 = 0;
  lm->de4 = 0;
  lm->de5 = 0;
  lm->valstraight = 0;
  *val = lm;
}

int	my_putchar(char c)
{
	write(2, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;

	while (str[i])
		my_putchar(str[i++]);
	my_putchar('\n');
	return (0);
}
int	my_put_error(char *str)
{
	my_putstr(str);
	return (84);
}

int	char_is_num(char c, t_mapsize *ms)
{
	if (c < '0' || c > '6')
		return (84);
	if (c >= '0' && c <= '6')
		return (0);
	else
		return (84);
	return (0);
}

int	comb_is_pair(char *str)
{
	if (strncmp(str, "pair_", 5) == 0 && strlen(str) == 6)
		return (0);
	else
		return (84);
}

int	comb_is_three(char *str)
{
	if (strncmp(str, "three_", 6) == 0 && strlen(str) == 7)
		return (0);
	else
		return (84);
}

int	comb_is_four(char *str)
{
	if (strncmp(str, "four_", 5) == 0 && strlen(str) == 6)
		return (0);
	else
		return (84);
}

int	comb_is_full(char *str)
{
	if (strncmp(str, "full_", 5) == 0 && strlen(str) == 8)
		return (0);
	else
		return (84);
}

int	char_is_full(char c, char d)
{
	if ((c <= '0' || c > '6') || (d <= '0' || d > '6'))
		return (84);
	if (c == d)
		return (1);
	if ((c >= '0' && c <= '6') && (d >= '0' && d <= '6'))
		return (0);
	else
		return (84);
}

int	comb_is_straight(char *str)
{
	if (strncmp(str, "straight_", 9) == 0 && strlen(str) == 10)
		return (0);
	else
		return (84);
}

int	comb_is_yams(char *str)
{
	if (strncmp(str, "yams_", 5) == 0 && strlen(str) == 6)
		return (0);
	else
		return (84);
}

int	any_comb_found(char *str)
{
	if ((strncmp(str, "pair_", 5) == 0 && strlen(str) == 6) || (strncmp(str, "three_", 6) == 0 && strlen(str) == 7) || (strncmp(str, "four_", 5) == 0 && strlen(str) == 6) || (strncmp(str, "full_", 5) == 0 && strlen(str) == 8) || (strncmp(str, "straight_", 9) == 0 && strlen(str) == 10) || (strncmp(str, "yams_", 5) == 0 && strlen(str) == 6))
		return (0);
	else
		return (84);
}

int	char_is_straight(char c, t_mapsize *ms)
{
	if (c < '5')
		return (84);
	if (c == '5' || c == '6')
		return (0);
	if (c != '5' || c != '6')
		return (84);
	return (0);
}

int	check_c(char *str, char **av, t_mapsize *ms)
{
	if (comb_is_pair(str) == 0 && char_is_num(str[5], ms) == 84)
		return (my_put_error("ERROR: Please enter a valid number for a pair !"));
	if (comb_is_pair(str) == 0 && str[5] == '0')
		return (my_put_error("ERROR: Please enter a valid number for a pair_!"));
	if (comb_is_pair(str) == 0 && char_is_num(str[5], ms) == 0)
	{
		ms->A = str[5] - 48;
		return (0);
	}
	if (comb_is_three(str) == 0 && char_is_num(str[6], ms) == 84)
		return (my_put_error("ERROR: Please enter a valid number for a three !"));
	if (comb_is_three(str) == 0 && str[6] == '0')
		return (my_put_error("ERROR: Please enter a valid number for a three_ !"));
	if (comb_is_three(str) == 0 && char_is_num(str[6], ms) == 0)
	{
		ms->A = str[6] - 48;
		return (0);
	}
	if (comb_is_four(str) == 0 && char_is_num(str[5], ms) == 84)
		return (my_put_error("ERROR: Please enter a valid number for a four !"));
	if (comb_is_four(str) == 0 && str[5] == '0')
		return (my_put_error("ERROR: Please enter a valid number for a four_ !"));
	if (comb_is_four(str) == 0 && char_is_num(str[5], ms) == 0)
	{
		ms->A = str[5] - 48;
		return (0);
	}
	if (comb_is_full(str) == 0 && char_is_full(str[5], str[7]) == 1)
		return ((my_put_error("ERROR: You can't specify the same value for a full")));
	if (comb_is_full(str) == 0 && char_is_full(str[5], str[7]) == 84)
		return (my_put_error("ERROR: Please enter a valid number for a full !"));
	if (comb_is_full(str) == 0 && char_is_full(str[5], str[7]) == 0)
	{
		ms->A = str[5] - 48;
		ms->B = str[7] - 48;
		return (0);
	}
	if (comb_is_straight(str) == 0 && char_is_straight(str[9], ms) == 84)
		exit (my_put_error("ERROR: a straight cannot be < 5!"));
	if (comb_is_straight(str) == 0 && char_is_num(str[9], ms) == 0)
	{
		ms->A = str[9] - 48;
		return (0);
	}
	if (comb_is_yams(str) == 0 && char_is_num(str[5], ms) == 84)
		return (my_put_error("ERROR: Please enter a valid number for a yams !"));
	if (comb_is_yams(str) == 0 && str[5] == '0')
		return (my_put_error("ERROR: Please enter a valid number for a yams_ !"));
	if (comb_is_yams(str) == 0 && char_is_num(str[5], ms) == 0)
	{
		ms->A = str[5] - 48;
		return (0);
	}
	if (any_comb_found(str) == 84)
		return (84);
}

int	check_args(int ac, char **av, t_mapsize *ms)
{
	char	*str = malloc(sizeof(char) * strlen(av[6]));
	str = av[6];
	char	*de1 = malloc(sizeof(char) * strlen(av[1]));
	de1 = av[1];
	char	*de2 = malloc(sizeof(char) * strlen(av[2]));
	de2 = av[2];
	char	*de3 = malloc(sizeof(char) * strlen(av[3]));
	de3 = av[3];
	char	*de4 = malloc(sizeof(char) * strlen(av[4]));
	de4 = av[4];
	char	*de5 = malloc(sizeof(char) * strlen(av[5]));
	de5 = av[5];

	if (check_c(str, av, ms) == 84)
		return (my_put_error("ERROR: Unvalid combination specified"));
	if (strlen(de1) == 1 && char_is_num(de1[0], ms) == 84)
		return (my_put_error("ERROR: Enter a valid value for dice 1 (1 - 6)"));
	if (strlen(de2) == 1 && char_is_num(de2[0], ms) == 84)
		return (my_put_error("ERROR: Enter a valid value for dice 2 (1 - 6)"));
	if (strlen(de3) == 1 && char_is_num(de3[0], ms) == 84)
		return (my_put_error("ERROR: Enter a valid value for dice 3 (1 - 6)"));
	if (strlen(de4) == 1 && char_is_num(de4[0], ms) == 84)
		return (my_put_error("ERROR: Enter a valid value for dice 4 (1 - 6)"));
	if (strlen(de5) == 1 && char_is_num(de5[0], ms) == 84)
		return (my_put_error("ERROR: Enter a valid value for dice 5 (1 - 6)"));
	if (strlen(de1) != 1 || strlen(de2) != 1 || strlen(de3) != 1 || strlen(de4) != 1 || strlen(de5) != 1)
		return (my_put_error("ERROR: Float number detected, enter a valid value for dice (1 - 6)"));
	return (0);
}

int	my_getnbr(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	res = 0;
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

int	init_dice(t_mapsize *ms, char **av)
{
	ms->de1 = my_getnbr(av[1]);
	ms->de2 = my_getnbr(av[2]);
	ms->de3 = my_getnbr(av[3]);
	ms->de4 = my_getnbr(av[4]);
	ms->de5 = my_getnbr(av[5]);
	return (0);
}

int	times_in_tab(int *tab, int number)
{
	int	i = 0;
	int	j = 0;

	while (i < 5)
	{
		if (tab[i] == number)
			j++;
		i++;
	}
	return (j);
}

int     stock_in_tab(t_mapsize *ms)
{
        ms->tab = malloc(sizeof(int) * 5);
        ms->tab[0] = ms->de1;
        ms->tab[1] = ms->de2;
        ms->tab[2] = ms->de3;
        ms->tab[3] = ms->de4;
        ms->tab[4] = ms->de5;
	return (0);
}

int	check_valid_dice(char **av)
{
	if (atoi(av[1]) < 0 || atoi(av[1]) > 6)
		return (84);
	if (atoi(av[2]) < 0 || atoi(av[2]) > 6)
		return (84);
	if (atoi(av[3]) < 0 || atoi(av[3]) > 6)
		return (84);
	if (atoi(av[4]) < 0 || atoi(av[4]) > 6)
		return (84);
	if (atoi(av[5]) < 0 || atoi(av[5]) > 6)
		return (84);
	return (0);
}

int	check_av_full_zero(int ac, char **av)
{
	int	i = 1;

	if (atoi(av[1]) == 0 && atoi(av[2]) == 0 && atoi(av[3]) == 0 && atoi(av[4]) == 0 && atoi(av[5]) == 0)
		return (0);
	while (i < ac - 1)
	{
		if (atoi(av[i]) == 0)
			return (84);
		i++;
	}
	return (0);
}

int	factorial(int number)
{
	return (number <= 0) ? 1 : (number * factorial(number - 1));
}

double	binomial(double k, double n)
{
	return (factorial(k) / (factorial(n) * factorial(k - n))) * pow(0.166666, n) * pow(0.833333, k - n);
}


int	calc_pair(t_mapsize *ms)
{
	double res = 0;
	float	cent = 100.00;

	if ((int)ms->n >= (int)ms->k)
	{
		printf("chances to get a %d pair: %0.2f%%\n", ms->A, cent);
		return (0);
	} else {
		for (int x = ms->k - ms->n; x < (5 - ms->n + 1); x++) {
			res += binomial(5 - ms->n, x);
		}

		printf("chances to get a %d pair: %0.2f%%\n", ms->A, (double)(res * 100));
		return (0);
	}
}

int	calc_three(t_mapsize *ms)
{
	double res = 0;
	float	cent = 100.00;

	if ((int)ms->n >= (int)ms->k)
	{
		printf("chances to get a %d three-of-a-kind: %0.2f%%\n", ms->A, cent);
		return (0);
	} else {
		for (int x = ms->k - ms->n; x < (5 - ms->n + 1); x++) {
			res += binomial(5 - ms->n, x);
		}

		printf("chances to get a %d three-of-a-kind: %0.2f%%\n", ms->A, (double)(res * 100));
		return (0);
	}
}

int	calc_four(t_mapsize *ms)
{
	double res = 0;
	float	cent = 100.00;

	if ((int)ms->n >= (int)ms->k)
	{
		printf("chances to get a %d four-of-a-kind: %0.2f%%\n", ms->A, cent);
		return (0);
	} else {
		for (int x = ms->k - ms->n; x < (5 - ms->n + 1); x++) {
			res += binomial(5 - ms->n, x);
		}

		printf("chances to get a %d four-of-a-kind: %0.2f%%\n", ms->A, (double)(res * 100));
		return (0);
	}
}

int	calc_full(t_mapsize *ms)
{
	double res = 0;
	int	n;
	int	p;
	int	k;

        if ((int)ms->n > 3)
                ms->n = 3;
        if (ms->n2 > 2)
		ms->n2 = 2;

	n = 5 - ms->n - ms->n2;
	p = 3 - ms->n;
	k = n - p;
	res = (factorial(n) /(factorial(p) * factorial(k))) / pow(6, n) * 100;
	printf("chances to get a %d full of %d: %0.2f%%\n", ms->A, ms->B, res);
	return (0);
}

int	calc_straight(t_mapsize *ms)
{
	double	res = factorial(ms->n) / pow(6, ms->n);

	printf("chances to get a %d straight: %0.2f%%\n", ms->A, (res * 100));
	return (0);
}

int	calc_yams(t_mapsize *ms)
{
	double	res = 0;

	res = powf(0.166666, (5 - ms->nxintab));
	printf("chances to get a %d yams: %0.2f%%\n", ms->A, (res * 100));
	return (0);
}

int	main(int ac, char **av)
{
	t_mapsize	*ms;

	if (init_struct(&ms) == 84)
		return (84);
	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage());
	if (ac != 7)
		return (my_put_error("ERROR: Please enter 6 arguments (see -h)"));
	if (check_valid_dice(av) == 84)
		return (my_put_error("ERROR: All dices are invalid (0 - 6)"));
	if (check_av_full_zero(ac, av) == 84)
		return (my_put_error("ERROR: All dices must start with 0 if one is specified"));
	if (check_args(ac, av, ms) == 84)
		return (84);
	init_dice(ms, av);
	stock_in_tab(ms);
	if (comb_is_yams(av[6]) == 0)
	{
		ms->nxintab = times_in_tab(ms->tab, ms->A);
		calc_yams(ms);
		return (0);
	}
	if (comb_is_pair(av[6]) == 0)
	{
		ms->nxintab = times_in_tab(ms->tab, ms->A);
		ms->k = 2;
		ms->n = ms->nxintab;
		if (ms->n == 0)
			ms->k = 2;
		calc_pair(ms);
		return (0);
	}
	if (comb_is_three(av[6]) == 0)
	{
		ms->nxintab = times_in_tab(ms->tab, ms->A);
		ms->k = 3;
		ms->n = ms->nxintab;
		if (ms->n == 0)
			ms->k = 3;
		calc_three(ms);
		return (0);
	}
	if (comb_is_four(av[6]) == 0)
	{
		ms->nxintab = times_in_tab(ms->tab, ms->A);
		ms->k = 4;
		ms->n = ms->nxintab;
		if (ms->n == 0)
			ms->k = 4;
		calc_four(ms);
		return (0);
	}
	if (comb_is_full(av[6]) == 0)
	{
		ms->naxintab = times_in_tab(ms->tab, ms->A);
		ms->nbxintab = times_in_tab(ms->tab, ms->B);
		ms->k = 3;
		ms->n = ms->naxintab;
		ms->k2 = 2;
		ms->n2 = ms->nbxintab;
		calc_full(ms);
		return (0);
	}
	if (comb_is_straight(av[6]) == 0)
	{
		ms->n = (5 - intcmp(ms->tab, ms, ms->A));
		calc_straight(ms);
		return (0);
	}
	return (0);
}
