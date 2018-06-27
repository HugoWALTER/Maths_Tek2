/*
** EPITECH PROJECT, 2018
** 209poll
** File description:
** 209poll.c
*/

#include "my.h"

int	usage(void)
{
	printf("USAGE\n\t./209poll pSize sSize p\n\nDESCRIPTION\n\tppSize\tsize of the population\n\tsSize\tsize of the sample (supposed to be representative)\n\tp\tpercentage of voting intentions for a specific candidate\n");
	exit(0);
}

int	init_struct(t_mapsize **val)
{
	t_mapsize	*lm;

	if ((lm = malloc(sizeof(*lm))) == NULL)
		return (84);
	lm->N = 0;
	lm->n = 0;
	lm->p = 0;
	lm->variance = 0;
	lm->min_95 = 0;
	lm->max_95 = 0;
	lm->min_99 = 0;
	lm->max_99 = 0;
	lm->x_bar = 0;
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
	if (check_float(av[1]) == 84)
		return (my_put_error("Size of the population must be an integer"));
	if (check_float(av[2]) == 84)
		return (my_put_error("Size of the sample must be an integer"));
	ms->N = atoi(av[1]);
	ms->n = atoi(av[2]);
	if (ms->N <= 0)
		return (my_put_error("Size of the population must be > 0"));
	if (ms->n <= 0)
		return (my_put_error("Size of the sample must be > 0"));
	if (ms->n > ms->N)
		return (my_put_error("Population must be greater than the sample"));
	ms->p = atof(av[3]);
	if (ms->p <= 0 || ms->p > 100)
		return (my_put_error("Percentage must be > 0"));
	return (0);
}

int	calc_variance(t_mapsize *ms)
{
	double	vx = 0;
	double	v = 0;

	ms->x_bar = (ms->p / 100);
	vx = (ms->p / 100) * (1 - ms->p / 100);
	v = (vx * (ms->N - ms->n)) / (ms->n * (ms->N - 1));
	ms->variance = v;
	return (0);
}

int	calc_95(t_mapsize *ms)
{
	ms->min_95 = (2 * 1.96 * sqrtf(ms->variance)) / 2 * 100;
	ms->min_95 = ms->x_bar * 100 - ms->min_95;
	if (ms->min_95 <= 0)
		ms->min_95 = 0.00;
	ms->max_95 = (2 * 1.96 * sqrtf(ms->variance)) / 2 * 100;
	ms->max_95 = ms->x_bar * 100 + ms->max_95;
	if (ms->max_95 >= 100)
		ms->max_95 = 100.00;
	return (0);
}

int	calc_99(t_mapsize *ms)
{
	ms->min_99 = (2 * 2.58 * sqrtf(ms->variance)) / 2 * 100;
	ms->min_99 = ms->x_bar * 100 - ms->min_99;
	if (ms->min_99 <= 0)
		ms->min_99 = 0.00;
	ms->max_99 = (2 * 2.58 * sqrtf(ms->variance)) / 2 * 100;
	ms->max_99 = ms->x_bar * 100 + ms->max_99;
	if (ms->max_99 >= 100)
		ms->max_99 = 100.00;
	return (0);
}

int	main(int ac, char **av)
{
	t_mapsize	*ms;

	if (init_struct(&ms) == 84)
		return (84);
	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage());
	if (ac < 4 || ac > 4)
		return (my_put_error("ERROR: Please enter 3 integers and 1 float (see -h)"));
	if (check_args(ac, av, ms) == 84)
		return (84);
//	printf("ARGV: %d %d %f\n", atoi(av[1]), atoi(av[2]), atof(av[3]));
	printf("population size:\t\t%d\n", ms->N);
	printf("sample size:\t\t\t%d\n", ms->n);
	printf("voting intentions:\t\t%g%%\n", ms->p);
	calc_variance(ms);
	printf("variance:\t\t\t%f\n", ms->variance);
	calc_95(ms);
	printf("95%% confidence interval:\t [%0.2f%% ; %0.2f%%]\n", ms->min_95, ms->max_95);
	calc_99(ms);
	printf("99%% confidence interval:\t [%0.2f%% ; %0.2f%%]\n", ms->min_99, ms->max_99);
	free(ms);
	return (0);
}
