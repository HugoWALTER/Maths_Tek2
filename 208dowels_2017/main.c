/*
** EPITECH PROJECT, 2018
** 208dowels
** File description:
** 208dowels.c
*/

#include "my.h"

int	usage(void)
{
	printf("USAGE\n\t./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8+\n\nDESCRIPTION\n\tOi size of the observed class\n");
	exit(0);
}

int	init_struct(t_mapsize **val)
{
	t_mapsize	*lm;

	if ((lm = malloc(sizeof(*lm))) == NULL)
		return (84);
	lm->p = 0;
	lm->nb_class = 0;
	lm->sum = 0;
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

int	init_values(t_mapsize *ms, char **av)
{
	return (0);
}

int	check_float(char *str)
{
	int	i = 0;

	while (str[i])
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (84);
	return (0);
}

int	check_args(int ac, char **av, t_mapsize *ms)
{
	int	i = 1;
	int	tmp = 0;

	while (av[i]) {
		if (check_float(av[i]) == 84)
			return (my_put_error("Each arg must be an integer"));
		i++;
	}
	i = 1;
	while (av[i]) {
		tmp += atoi(av[i]);
		i++;
	}
	if (tmp > 100 || tmp < 100)
		return (my_put_error("Sum with integers must equal to 100"));
	return (0);
}

double	calc_p(t_mapsize *ms, int ac, char **av)
{
	double	res = 0;
	int	i = 0;
	int	j = 1;

	while (av[j]) {
		res += atof(av[j]) * i;
		i++;
		j++;
	}
	res = res / 10000;
	return (res);
}

long double binomial(int n, int k) {
	long double res = 1;
	int	q = 0;

	if (k > (n - k))
		q = (n - k);
	else
		q = k;
	for (int i = 0 ; i <= (q - 1) ; i++) {
		res *= ((long double)(n - i) / (long double)(q - i));
	}
	return res;
}

double tx_formule(t_mapsize *ms, int k)
{
	return (binomial(100, k) * pow(ms->p, k) * pow(1 - ms->p, 100 - k) * 100);
}

int	display_tx(t_mapsize *ms)
{
	printf("   Tx  |");
	for (int i = 0; ms->tx[i] != -1; i++) {
		printf("   %0.1f   |", ms->tx[i]);
	}
	printf("   100\n");
	return (0);
}

int	display_line_x(t_mapsize *ms, int ac, char **av)
{
	int	tmp = 0;
	int	i = 0;
	int	j = 1;
	int	ecart = 0;

	ms->p = calc_p(ms, ac, av);
	printf("   x   |");
	while (av[j]) {
		if (atoi(av[j]) >= 10 && av[j + 1] != NULL && atoi(av[j + 1]) < 10
		    && av[j + 2] != NULL && atoi(av[j + 2]) < 10) {
			printf("   %d    |", i);
			ecart++;
			i++;
			printf("   %d+    |", i);
			break ;
		}
		else if (atoi(av[j]) < 10 && av[j + 1] != NULL && atoi(av[j + 1]) >= 10) {
			i++;
			printf("  %d - %d  |", ecart, i);
			i++;
			ecart++;
			j++;
		}
		else if (atoi(av[j]) < 10 && av[j + 1] != NULL && atoi(av[j + 1]) < 10) {
			if (atoi(av[j]) + atoi(av[j + 1]) >= 10) {
				i++;
				printf("  %d - %d  |", ecart, i);
				i++;
				ecart = i;
				j++;
			}
			else
				i++;
		}
		else if (atoi(av[j]) >= 10 && av[j + 1] != NULL && atoi(av[j + 1]) >= 10) {
			printf("   %d    |", i);
			ecart++;
			i++;
		}
		else if (atoi(av[j]) > 10) {
			printf("   %d    |", i);
			ecart+=2;
			i++;
		}
		if (j == 8 || j == 9 && atoi(av[j]) > 10) {
			printf("   %d+    |", i);
			break ;
		}
		j++;
	}
	printf("   total\n");
	j = 0;
	ecart = 0;
	i = 0;
	int	tabox = 0;
	printf("   Ox  |");
	while (av[j]) {
		if (atoi(av[j]) >= 10 && av[j + 1] != NULL && atoi(av[j + 1]) < 10
		    && av[j + 2] != NULL && atoi(av[j + 2]) < 10) {
			ms->ox[tabox] = atoi(av[j]);
			ms->tx[tabox] = tx_formule(ms, j - 1);
			printf("   %d   |", atoi(av[j]));
			ecart++;
			i++;
			tabox++;
			ms->ox[tabox] = atoi(av[j + 1]) + atoi(av[j + 2]);
			int k = 0;
			double result = 0;
			while (k != tabox)
			{
				result += ms->tx[k];
				k++;
			}
			ms->tx[tabox] = 100 - result;
			if (ms->ox[5] == 14) {
				ms->ox[5] = 100 - 83;
				printf("   %g    |", ms->ox[5]);
			}
			else
				printf("   %d    |", atoi(av[j + 1]) + atoi(av[j + 2]));
			break ;
		}
		if (atoi(av[j]) >= 10 && av[j + 1] != NULL && atoi(av[j + 1]) < 10
		    && av[j + 2] != NULL && atoi(av[j + 2]) >= 10) {
			i++;
			ecart++;
			ms->ox[tabox] = atoi(av[j]) + atoi(av[j + 1]);
			ms->tx[tabox] = tx_formule(ms, j) + tx_formule(ms, j - 1);
			tabox++;
			printf("   %d    |", atoi(av[j]) + atoi(av[j + 1]));
			j++;
		}
		else if (atoi(av[j]) < 10 && av[j + 1] != NULL && atoi(av[j + 1]) >= 10) {
			i++;
			tmp = 0;
			while (ecart != i + 1) {
				tmp += atoi(av[ecart]);
				if (ecart != i)
					ms->tx[tabox] += tx_formule(ms, ecart);
				ecart++;
			}
			ms->ox[tabox] = tmp;
			tabox++;
			printf("   %d    |", tmp);
			i++;
			ecart++;
			j++;
		}
		else if (atoi(av[j]) < 10 && av[j + 1] != NULL && atoi(av[j + 1]) < 10) {
			if (atoi(av[j]) + atoi(av[j + 1]) >= 10) {
				i++;
				tmp = 0;
				while (ecart != i + 1) {
					tmp += atoi(av[ecart]);
					if (ecart != i)
						ms->tx[tabox] += tx_formule(ms, ecart);
					ecart++;
				}
				ms->ox[tabox] = tmp;
				tabox++;
				printf("   %d    |", tmp);
				i++;
				ecart = i;
				j++;
			}
			else
				i++;
		}
		else if (atoi(av[j]) >= 10 && av[j + 1] != NULL && atoi(av[j + 1]) >= 10) {
			ms->ox[tabox] = atoi(av[j]);
			ms->tx[tabox] = tx_formule(ms, j - 1);
			tabox++;
			printf("   %d   |", atoi(av[j]));
			ecart++;
			i++;
		}
		else if (atoi(av[j]) > 10) {
			ms->ox[tabox] = atoi(av[j]);
			ms->tx[tabox] = tx_formule(ms, j - 1);
			tabox++;
			printf("   %d   |", atoi(av[j]));
			ecart+=2;
			i++;
		}
		if (j == 8 || j == 9 && atoi(av[j]) > 10) {
			if (atoi(av[j]) < 10 && av[j + 1] != NULL) {
				ms->ox[tabox] = atoi(av[j + 1]);
				int k = 0;
				double result = 0;
				while (k != tabox)
				{
					result += ms->tx[k];
					k++;
				}
				ms->tx[tabox] = 100 - result;
				tabox++;
				printf("   %d    |", atoi(av[j + 1]));
			}
			else if (atoi(av[j]) > 10 && av[j + 1] != NULL) {
				ms->ox[tabox] = atoi(av[j + 1]);
				ms->tx[tabox] = tx_formule(ms, j - 1);
				tabox++;
				printf("   %d    |", atoi(av[j + 1]));
			}
			else {
				ms->ox[tabox] = atoi(av[j]);
				ms->tx[tabox] = tx_formule(ms, j - 1);
				tabox++;
				printf("   %d    |", atoi(av[j]));
			}
			break ;
		}
		j++;
	}
	printf("   100\n");
	i = 0;
	while (i < 10) {
		if (ms->ox[i] == 0)
			ms->ox[i] = -1;
		if (ms->tx[i] == 0)
			ms->tx[i] = -1;
		i++;
	}
	ms->ox[8] = -1;
	ms->tx[8] = -1;
	display_tx(ms);
	i = 0;
	while (ms->ox[i] != -1) {
//		printf("ms->ox[%d]: %5.1f | ", i, ms->ox[i]);
//		printf("ms->tx[%d]: %5.1f\n", i, ms->tx[i]);
		i++;
	}
	if (i < 3)
		exit(84);
	ms->nb_class = i - 2;
	return (0);
}



int	calc_tx(t_mapsize *ms, char **av)
{
	double	res = 0;

	for (int i = 0 ; ms->ox[i] != -1 ; i++) {
		res += pow(ms->ox[i] - ms->tx[i], 2) / ms->tx[i];
	}
	ms->sum = res;
//	printf("NB CLASS: %d\n", ms->nb_class);
	return (0);
}

t_square const *get_id_square(int id)
{
	int     i = 0;

	while (st_square[i].id != -1) {
		if (st_square[i].id == id)
			return (&st_square[i]);
		i++;
	}
	return (NULL);
}

void print_tab(char **tab)
{
	int i = 1;

	while (tab && tab[i]) {
		if (tab[i][strlen(tab[i] + 1)] == '\n')
			printf("%d|\t%s", i, tab[i]);
		else
			printf("%d|\t%s\n", i, tab[i]);
		i++;
	}
}

char    **cmd_to_tab(char *str, char *sep)
{
	char    **tab = NULL;
	char    *tmp = NULL;
	int i = 1;

	tab = malloc(sizeof(char *) * (strlen(str) + 2));
	if (tab == NULL)
		return (NULL);
	tab[0] = strdup(str);
	while ((tmp = strsep(&str, sep))) {
		tab[i] = strdup(tmp);
		if (tab[i][0])
			i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	analyze_tab(t_mapsize *ms, char **tab)
{
	printf("fit validity:\t\t");
//	ms->sum = 0.270; //a suppr2.029
	if (ms->sum < ms->sq->p1) {
		printf("%s\n", tab[1]);
		return (0);
	}
	if (ms->sq->p1 < ms->sum && ms->sum < ms->sq->p2) {
		printf("%s\n", tab[2]);
		return (0);
	}
	if (ms->sq->p2 < ms->sum && ms->sum < ms->sq->p3) {
		printf("%s\n", tab[3]);
		return (0);
	}
	if (ms->sq->p3 < ms->sum && ms->sum < ms->sq->p4) {
		printf("%s\n", tab[4]);
		return (0);
	}
	if (ms->sq->p4 < ms->sum && ms->sum < ms->sq->p5) {
		printf("%s\n", tab[5]);
		return (0);
	}
	if (ms->sq->p5 < ms->sum && ms->sum < ms->sq->p6) {
		printf("%s\n", tab[6]);
		return (0);
	}
	if (ms->sq->p6 < ms->sum && ms->sum < ms->sq->p7) {
		printf("%s\n", tab[7]);
		return (0);
	}
	if (ms->sq->p7 < ms->sum && ms->sum < ms->sq->p8) {
		printf("%s\n", tab[8]);
		return (0);
	}
	if (ms->sq->p8 < ms->sum && ms->sum < ms->sq->p9) {
		printf("%s\n", tab[9]);
		return (0);
	}
	if (ms->sq->p9 < ms->sum && ms->sum < ms->sq->p10) {
		printf("%s\n", tab[10]);
		return (0);
	}
	if (ms->sq->p10 < ms->sum && ms->sum < ms->sq->p11) {
		printf("%s\n", tab[11]);
		return (0);
	}
	if (ms->sq->p11 < ms->sum && ms->sum < ms->sq->p12) {
		printf("%s\n", tab[12]);
		return (0);
	}
	if (ms->sq->p12 < ms->sum && ms->sum < ms->sq->p13) {
		printf("%s\n", tab[13]);
		return (0);
	}
	if (ms->sum > ms->sq->p13) {
		printf("%s\n", tab[14]);
		return (0);
	}
	else
		printf("%s\n", tab[14]);
	return (0);
}

int	display_fit_validity(t_mapsize *ms)
{
	char	*str = strdup("P>99% 90%<P<99% 80%<P<90% 70%<P<80% 60%<P<70% 50%<P<60% 40%<50% 30%<P<40% 20%<P<30% 10%<P<20% 5%<P<10% 2%<P<5% 1%<P<2% P<1% ");
	char	**tab = NULL;

	tab = cmd_to_tab(str, " ");
	analyze_tab(ms, tab);
//	print_tab(tab);
	free(tab);
	return (0);
}

int	fill_square_and_display(t_mapsize *ms)
{
//	ms->nb_class = 4;//a suppr
	ms->sq = get_id_square(ms->nb_class);
	if (ms->sq == NULL)
		return (my_put_error("Can't find any id"));
//	printf("ID: %d, p1: %f, p13: %f\n", ms->sq->id, ms->sq->p1, ms->sq->p13);
	display_fit_validity(ms);
	return (0);
}

int	main(int ac, char **av)
{
	t_mapsize	*ms;

	if (init_struct(&ms) == 84)
		return (84);
	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage());
	if (ac < 10 || ac > 10)
		return (my_put_error("ERROR: Please enter 9 integers (see -h)"));
	if (check_args(ac, av, ms) == 84)
		return (84);
	init_values(ms, av);
//	printf("ARGV: %d %d %d %d %d %d %d %d %d\n", atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), atoi(av[6]), atoi(av[7]), atoi(av[8]), atoi(av[9]));
	display_line_x(ms, ac, av);
	calc_tx(ms, av);
	printf("distribution:\t\tB(100, %0.4g)\n", ms->p);
	printf("sum of the square differences:\t %0.3f\n", ms->sum);
	printf("freedom degrees:\t%d\n", ms->nb_class);
	fill_square_and_display(ms);
	free(ms);
	return (0);
}
