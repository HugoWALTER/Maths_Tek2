/*
** EPITECH PROJECT, 2018
** 205IQ
** File description:
** 205IQ.c
*/

#include "my.h"

int	usage(void)
{
	printf("USAGE\n\t./206neutrinos n a h sd\n\nDESCRIPTION\n\tn\tnumber of values\n\ta\tarithmetic mean\n\th\tharmonic mean\n\tsd\tstandard deviation\n");
	exit(0);
}

int	init_struct(t_mapsize **val)
{
	t_mapsize	*lm;

	if ((lm = malloc(sizeof(*lm))) == NULL)
		return (84);
	lm->n = 0;
	lm->a = 0;
	lm->h = 0;
	lm->sd = 0;
	lm->value = NULL;
	lm->val = 0;
	lm->first = 0;
	lm->second = 0;
	lm->third = 0;
	lm->quadra = 0;
	lm->penta = 0;
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
	ms->n = atoi(av[1]);
	ms->a = atoi(av[2]);
	ms->h = atoi(av[3]);
	ms->sd = atoi(av[4]);
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
	if (check_float(av[1]) == 84)
		return (my_put_error("n must be an integer"));
	if (check_float(av[2]) == 84)
		return (my_put_error("a must be an integer"));
	if (atoi(av[1]) <= 0)
		return (my_put_error("n must be > 0"));
	if (atoi(av[2]) <= 0)
		return (my_put_error("a must be > 0"));
	if (check_float(av[3]) == 84)
		return (my_put_error("h must be an integer"));
	if (atoi(av[3]) <= 0)
		return (my_put_error("h must be > 0"));
	if (check_float(av[4]) == 84)
		return (my_put_error("sd must be an integer"));
	if (atoi(av[4]) <= 0)
		return (my_put_error("sd must be between 0 and 200"));
	if (atoi(av[3]) < atoi(av[2]))
		return (my_put_error("h must be more than a"));
	return (0);
}

int	calc_first(t_mapsize *ms)
{
	ms->first = ms->n + 1;
	return (0);
}

int	calc(t_mapsize *ms)
{
	double calc_arith = ms->third * ms->n;
	double quadridic = ((pow(ms->second, 2) + pow(ms->third, 2)) * ms->n);

	ms->n++;
	ms->third = (calc_arith + ms->val) / ms->n;
	ms->second = sqrt(((quadridic + pow(ms->val, 2)) / ms->n) - pow(ms->third, 2));
	ms->quadra = sqrt((quadridic + pow(ms->val, 2)) / ms->n);
	ms->penta = ms->n / ((1 / ms->val) + ((ms->n - 1) / ms->penta));
	return (0);
}

int	display_res(t_mapsize *ms)
{
	printf("\tantal mãlinder :\t%d\n", ms->first);
	printf("\tstandardafvilgelse :\t%0.2f\n", ms->second);
	printf("\taritmetisk gennemsnit :\t%0.2f\n", ms->third);
	printf("\tkvadratisk gennemsnit :\t%0.2f\n", ms->quadra);
	printf("\tharmonisk gennemsnit :\t%0.2f\n\n", ms->penta);
	return (0);
}

int	init_results(t_mapsize *ms)
{
	ms->first = ms->n;
	ms->second = (double)ms->sd;
	ms->third = (double)ms->a;
	ms->quadra = 0;
	ms->penta = (double)ms->h;
	return (0);
}

int	check_int_or_empty(char *str)
{
	int	i = 0;
	int	len = strlen(str);

	str[len - 1] = '\0';
	while (str[i] != '\0')
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			i++;
		else
			return (84);
	if (str[0] == '\0')
		return (84);
	return (0);
}

int	read_input(t_mapsize *ms)
{
	size_t	buffsize = 2048;
	char	*buffer = malloc(sizeof(char) * buffsize);
	size_t	c = 0;
	int	i = 0;

	if (buffer == NULL)
		return (84);
	init_results(ms);
	while (1) {
		i = 0;
		printf("indtast din vaerdi : ");
		c = getline(&buffer, &buffsize, stdin);
		buffer[c] = '\0';
		if (strncmp(buffer, "ENDE", 4) == 0)
			break;
		if (check_int_or_empty(buffer) == 84)
			i = 1;
/*		if (check_float(buffer) == 84)
		i = 1;*/
		if (i == 0) {
			ms->val = atof(buffer);
			calc_first(ms);
			calc(ms);
			display_res(ms);
			i = 0;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mapsize	*ms;

	if (init_struct(&ms) == 84)
		return (84);
	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage());
	if (ac < 5 || ac > 5)
		return (my_put_error("ERROR: Please enter 4 arguments (see -h)"));
	if (check_args(ac, av, ms) == 84)
		return (84);
	init_values(ms, av);
	read_input(ms);
	free(ms);
	return (0);
}
