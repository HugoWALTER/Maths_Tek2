/*
** EPITECH PROJECT, 2018
** 205IQ
** File description:
** 205IQ.c
*/

#include "my.h"

int	usage(void)
{
	printf("USAGE\n\t./205IQ μ σ [IQ1] [IQ2]\nDESCRIPTION\n\tμ\tpredetermined mean\n\tσ\tpredetermined standard deviation\n\tIQ1\tminimum IQ\n\tIQ2\tmaximum IQ\n");
	exit(0);
}

int	init_struct(t_mapsize **val)
{
	t_mapsize	*lm;

	if ((lm = malloc(sizeof(*lm))) == NULL)
		return (84);
	lm->mu = 0;
	lm->ecart = 0;
	lm->miniq = 0;
	lm->maxiq = 0;
	lm->valarg = 0;
	lm->res = 0;
	lm->i = 1;
        lm->t2 = 0;
        lm->proba = 0;
        lm->probat = 0;
        lm->probat2 = 0;
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
	if (ms->valarg == 3) {
		ms->mu = atoi(av[1]);
		ms->ecart = atoi(av[2]);
	}
	if (ms->valarg == 4) {
		ms->mu = atoi(av[1]);
		ms->ecart = atoi(av[2]);
		ms->miniq = atoi(av[3]);
	}
	if (ms->valarg == 5) {
		ms->mu = atoi(av[1]);
		ms->ecart = atoi(av[2]);
		ms->miniq = atoi(av[3]);
		ms->maxiq = atoi(av[4]);
	}
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
	ms->valarg = ac;
	if (ac == 3) {
		if (check_float(av[1]) == 84)
			return (my_put_error("μ must be an integer"));
		if (check_float(av[2]) == 84)
			return (my_put_error("σ must be an integer"));
		if (atoi(av[1]) < 0 || atoi(av[1]) > 200)
			return (my_put_error("μ must be between 0 and 200"));
		if (atoi(av[2]) < 0 || atoi(av[2]) > 200)
			return (my_put_error("σ must be between 0 and 200"));
	}
	if (ac == 4) {
		if (check_float(av[1]) == 84)
			return (my_put_error("μ must be an integer"));
		if (check_float(av[2]) == 84)
			return (my_put_error("σ must be an integer"));
		if (atoi(av[1]) < 0 || atoi(av[1]) > 200)
			return (my_put_error("μ must be between 0 and 200"));
		if (atoi(av[2]) < 0 || atoi(av[2]) > 200)
			return (my_put_error("σ must be between 0 and 200"));
		if (check_float(av[3]) == 84)
			return (my_put_error("minIQ must be an integer"));
		if (atoi(av[3]) < 0 || atoi(av[3]) > 200)
			return (my_put_error("minIQ must be between 0 and 200"));
	}
	if (ac == 5) {
		if (check_float(av[1]) == 84)
			return (my_put_error("μ must be an integer"));
		if (check_float(av[2]) == 84)
			return (my_put_error("σ must be an integer"));
		if (atoi(av[1]) < 0 || atoi(av[1]) > 200)
			return (my_put_error("μ must be between 0 and 200"));
		if (atoi(av[2]) < 0 || atoi(av[2]) > 200)
			return (my_put_error("σ must be between 0 and 200"));
		if (check_float(av[3]) == 84)
			return (my_put_error("minIQ must be an integer"));
		if (atoi(av[3]) < 0 || atoi(av[3]) > 200)
			return (my_put_error("minIQ must be between 0 and 200"));
		if (check_float(av[4]) == 84)
			return (my_put_error("maxIQ must be an integer"));
		if (atoi(av[4]) < 0 || atoi(av[4]) > 200)
			return (my_put_error("maxIQ must be between 0 and 200"));
		if (atoi(av[4]) < atoi(av[3]))
			return (my_put_error("maxIQ is lower than lowIQ"));
	}
	return (0);
}

double	fct_normale(t_mapsize *ms, double t)
{
	return ((1 / (ms->ecart * sqrt(2 * M_PI))) * exp(-pow(((t - ms->mu) / ms->ecart), 2) / 2));
}

int	calc_only_mu_and_ecart(t_mapsize *ms)
{
	double	gauss = 0;

	for (int i = 0 ; i <= 200 ; i++) {
		gauss = fct_normale(ms, (double)i);
		ms->tab[i] = gauss * 100;
	}
	return (0);
}

int	display_res(t_mapsize *ms)
{
	for (int i = 0 ; i <= 200 ; i++) {
		printf("%d %0.2f\n", i, ms->tab[i]);
	}
	return (0);
}

double	proba(t_mapsize *ms)
{
	ms->proba = fct_normale(ms, 0);
	for (ms->i = 0 ; ms->i <= ms->miniq ; ms->i++) {
		ms->t2 = ms->i - 0.5;
		ms->probat = fct_normale(ms, ms->i);
		ms->probat2 = fct_normale(ms, ms->t2);
		ms->proba += (2 * ms->probat + 4 * ms->probat2) / 6;
	}
	ms->proba -=  fct_normale(ms, ms->miniq) / 6;
	return (ms->proba * 100);
}

double	proba_min_and_max(t_mapsize *ms, double nb)
{
	ms->proba = fct_normale(ms, 0);
	for (ms->i = 0 ; ms->i <= nb ; ms->i++) {
		ms->t2 = ms->i - 0.5;
		ms->probat = fct_normale(ms, ms->i);
		ms->probat2 = fct_normale(ms, ms->t2);
		ms->proba += (2 * ms->probat + 4 * ms->probat2) / 6;
	}
	ms->proba -=  fct_normale(ms, nb) / 6;
	return (ms->proba * 100);
}

int	calc_min_IQ(t_mapsize *ms)
{
	ms->res = 0;
	ms->res = proba(ms);
	return (0);
}

int	display_min_res(t_mapsize *ms)
{
	printf("%0.1f%% of people have an IQ inferior to %d\n",
		ms->res, ms->miniq);
	return (0);
}

int	calc_min_and_max_IQ(t_mapsize *ms)
{
	ms->res = 0;
	ms->res = (proba_min_and_max(ms, ms->maxiq) -
			proba_min_and_max(ms, ms->miniq));
	return (0);
}

int	display_min_and_max_res(t_mapsize *ms)
{
	printf("%0.1f%% of people have an IQ between %d and %d\n",
		ms->res, ms->miniq, ms->maxiq);
	return (0);
}

int	main(int ac, char **av)
{
	t_mapsize	*ms;

	if (init_struct(&ms) == 84)
		return (84);
	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage());
	if (ac < 3 || ac > 5)
		return (my_put_error("ERROR: Please enter 2 arguments (see -h)"));
	if (check_args(ac, av, ms) == 84)
		return (84);
	init_values(ms, av);
	if (ac == 3) {
		calc_only_mu_and_ecart(ms);
		display_res(ms);
	}
	if (ac == 4) {
		calc_min_IQ(ms);
		display_min_res(ms);
	}
	if (ac == 5) {
		calc_min_and_max_IQ(ms);
		display_min_and_max_res(ms);
	}
	free(ms);
	return (0);
}
