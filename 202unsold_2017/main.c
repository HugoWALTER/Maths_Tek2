/*
** EPITECH PROJECT, 2018
** 202unsold
** File description:
** 202unsold.c
*/

#include "my.h"

int	usage(void)
{
	printf("USAGE\n\t./202unsold a b\nDESCRIPTION\n\ta\tconstant computed from the past results\n\tb\tconstant computed from the past results\n");
	exit (0);
}

int	init_struct(t_mapsize **val)
{
  t_mapsize	*lm;

  if ((lm = malloc(sizeof(*lm))) == NULL)
	  return (84);
  lm->a = 0;
  lm->b = 0;
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

double	*init_tab(double *tab, int n)
{
	int	i = 0;

	if ((tab = malloc(sizeof(double) * n)) == NULL)
		return (NULL);
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

double	**init_double_tab(double **tab, int x, int y)
{
	int	i = 0;
	int	j = 0;

	if ((tab = malloc(sizeof(double *) * x)) == NULL)
		return (NULL);
	while (i < x)
	{
		if ((tab[i] = malloc(sizeof(double) * y)) == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}

int	init_values(t_mapsize *ms, char **av)
{
	ms->a = atoi(av[1]);
	ms->b = atoi(av[2]);
	ms->tab = init_double_tab(ms->tab, 6, 6);
	ms->tmptab = init_tab(ms->tmptab, 10);
	ms->somme = init_tab(ms->somme, 6);
	return (0);
}

int	check_float(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (84);
	}
	return (0);
}

int	check_args(t_mapsize *ms, char **av)
{
	int	a = atoi(av[1]);
	int	b = atoi(av[2]);

	if (check_float(av[1]) == 84)
		return (my_put_error("a must be an integer"));
	if (check_float(av[2]) == 84)
		return (my_put_error("b must be an integer"));
	if (a <= 50)
		return (my_put_error("a must be greater than 50"));
	if (b <= 50)
		return (my_put_error("b must be greater than 50"));
	return (0);
}

void	print_line(void)
{
	printf("------------------------------------------------------\n");
}

void	print_yline_law(void)
{
	int	i = 10;

	printf("\t");
	while (i < 60)
	{
		printf("X=%d\t", i);
		i+= 10;
	}
	printf("Y law\n");
}

void	print_zline_law(void)
{
	int	i = 20;

	printf("Z\t");
	while (i <= 100)
	{
		printf("%d\t", i);
		i+= 10;
	}
	printf("Total\n");
	printf("p(Z=z)");
}

int	print_xline_law(int y)
{
	if (y <= 50)
		printf("Y=%d", y);
	else
		printf("X law");
	return (0);
}

int	display_res(int y, double *somme)
{
	if (y == 60)
		printf("\t1\n");
	else
		printf("\t%0.3f\n", somme[5]);

	return (0);
}

float	formule(t_mapsize *ms, int x, int y)
{
	float	res = 0;

	res = (float)((ms->a - x) * (ms->b - y)) / (float)((5 * ms->a - 150) * (5 * ms->b - 150));
	return (res);
}

int	create_tab(t_mapsize *ms)
{
	int	i = 10;
	int	j = 10;

	while (j <= 60)
	{
		i = 10;
		ms->somme[5] = 0;
		print_xline_law(j);
		while (i <= 50)
		{
			if (j == 60)
				ms->tab[i / 10 - 1][j / 10 - 1] = ms->somme[i / 10 - 1];
			else
				ms->tab[i / 10 - 1][j / 10 - 1] = formule(ms, i, j);
			ms->somme[i / 10 - 1] += ms->tab[i / 10 - 1][j / 10 - 1];
			printf("\t%0.3f", ms->tab[i / 10 - 1][j / 10 - 1]);
			ms->somme[5] += ms->tab[i / 10 - 1][j / 10 - 1];
			i += 10;
		}
		display_res(j, ms->somme);
		ms->tab[i / 10 - 1][j / 10 - 1] = ms->somme[5];
		j += 10;
	}
	return (0);
}

int	calc_zlaw(t_mapsize *ms)
{
	int   i = 0;
	int   j = 0;

	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			ms->tmptab[i + j] += ms->tab[i][j];
			ms->tmptab[9] += ms->tab[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 9)
		printf("\t%0.3f", ms->tmptab[i++]);
	printf("\t1\n");
	return (0);
}

int	display_variance(double *var)
{
	printf("expected value of X:\t%0.1f\n", var[0]);
	printf("variance of X:\t\t%0.1f\n", var[1]);
	printf("expected value of Y:\t%0.1f\n", var[2]);
	printf("variance of Y:\t\t%0.1f\n", var[3]);
	printf("expected value of Z:\t%0.1f\n", var[4]);
	printf("variance of Z:\t\t%0.1f\n", var[5]);
	return (0);
}

double	*calc_expected_value(t_mapsize *ms, double *var)
{
	int	i = 0;

	while (i < 5)
	{
		var[0] += (i + 1) * 10 * ms->tab[i][5];
		var[2] += (i + 1) * 10 * ms->tab[5][i];
		var[4] += (i + 2) * 10 * ms->tmptab[i];
		i++;
	}
	return (var);
}

double	*calc_variance(t_mapsize *ms, double *var)
{
	int	i = 0;

	while (i < 5)
	{
		var[1] += pow(((i + 1) * 10 - var[0]), 2) * ms->tab[i][5];//var avec Y law
		var[3] += pow(((i + 1) * 10 - var[2]), 2) * ms->tab[5][i];//var avec X law
		if (i < 4)
			var[4] += (i + 7) * 10 * ms->tmptab[i + 5];
		i++;
	}
	i = 0;
	while (i < 9)
	{
		var[5] += pow(((i + 2) * 10 - var[4]), 2) * ms->tmptab[i];
		i++;
	}
	return (var);
}

int	calc_step3(t_mapsize *ms)
{
	double	*var = init_tab(var, 6);

	var = calc_expected_value(ms, var);
	var = calc_variance(ms, var);
	display_variance(var);
	return (0);
}

int	first_step(t_mapsize *ms)
{
	print_line();
	print_yline_law();
	create_tab(ms);
	print_line();
	return (0);
}

int	second_step(t_mapsize *ms)
{
	print_zline_law();
	calc_zlaw(ms);
	print_line();
	return (0);
}

int	third_step(t_mapsize *ms)
{
	calc_step3(ms);
	print_line();
	return (0);
}

int	main(int ac, char **av)
{
	t_mapsize	*ms;

	if (init_struct(&ms) == 84)
		return (84);
	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage());
	if (ac != 3)
		return (my_put_error("ERROR: Please enter 2 arguments (see -h)"));
	if (check_args(ms, av) == 84)
		return (84);
	init_values(ms, av);
	first_step(ms);
	second_step(ms);
	third_step(ms);
	return (0);
}
