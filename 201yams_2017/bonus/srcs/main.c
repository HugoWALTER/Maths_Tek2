/*
** EPITECH PROJECT, 2018
** yams
** File description:
** main.c
*/

#include "my.h"

void	destroy(t_mapsize *ms)
{
  sfRenderWindow_destroy(ms->window);
}

t_mapsize	*init_struct(t_mapsize *ms)
{
  if ((ms = malloc(sizeof(t_mapsize))) == NULL)
    return (NULL);
  ms->tour = 0;
  ms->score = 0;
  ms->attempts = 3;
  ms->valtext = 0;
  ms->valalgo = 0;
  ms->scoretemp = 0;
  ms->update = 0;
  return (ms);
}

void    update_texture(t_mapsize *ms)
{
  sfRenderWindow_clear(ms->window, sfBlack);
  sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
			     ms->structure->width,
			     ms->structure->height, 0, 0);
  sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
  sfRenderWindow_drawText(ms->window, ms->launch, NULL);
  sfRenderWindow_display(ms->window);
}

int	calc_score(t_mapsize *ms)
{
	printf("algo: %d\n", ms->valalgo);
	if (ms->valtext == 1)
		return ((ms->valalgo * 2));
	if (ms->valtext == 2)
		return ((ms->valalgo * 2 + 5));
	if (ms->valtext == 3)
		return ((ms->valalgo * 3));
	if (ms->valtext == 6)
		return ((ms->valalgo * 4));
	if (ms->valtext == 4)
		return (25);
	if (ms->valtext == 5)
		return (30);
	if (ms->valtext == 10)
		return (50);
	return (0);
}
int	main(int ac, char **av)
{
	t_mapsize		*ms;
	t_my_framebuffer	*fb;
	sfVector2i		mp;
	static int	firstlance = 0;

	ms = init_struct(ms);
	initialisation(ms);
	create_textures(ms); //create texture et sprites
	create_txt(ms);
	create_tour(ms);
	create_dices(ms);
	update_menu(ms);
	while (sfRenderWindow_isOpen(ms->window))
	{
		while (sfRenderWindow_pollEvent(ms->window, &ms->event))
		{
			if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
			{
				mp = sfMouse_getPosition((sfWindow *) ms->window);
//				printf("x: %d\n y: %d\n", mp.x, mp.y);
				if (mp.x > 246 && mp.x < 526 && mp.y > 868 && mp.y < 930) //launch
				{
					ms->attempts = 3;
					sfText_setString(ms->tnbattempts, ms->nbattemptsstr);
					ms->tour++;
					if (ms->tour == 11)
					{
						create_endscreen(ms);
						update_end(ms);
						sleep(5);
						exit(0);
					}
					randomize_dices(ms);
					fade_dices(ms);
					ms->valtext = my_algo(ms);
					ms->lastscore = ms->score;
					if (ms->tour == 5 && ms->score >= 63)
						ms->score += 35;
					if (ms->scoretemp == 0 && firstlance == 1)
						ms->score += calc_score(ms);
					if (ms->scoretemp == 0 && firstlance == 0)
					{
						ms->score += calc_score(ms);
						firstlance = 1;
					}
					if (ms->scoretemp > 0)
						ms->score += calc_score(ms);
					set_tour(ms);
					sfText_setString(ms->tnbscore, ms->nbscorestr);
					update_dice5(ms);
				}
				if (mp.x > 263 && mp.x < 528 && mp.y > 684 && mp.y < 755 && ms->attempts > 0 && ms->tour > 0)
				{
					ms->scoretemp = 0;
					randomize_dices(ms);
					fade_dices(ms);
					ms->valtext = my_algo(ms);
					ms->scoretemp = calc_score(ms);
					ms->score = (ms->lastscore + ms->scoretemp);
					ms->scoretemp = ms->score;
					ms->attempts--;
					set_tour(ms);
					sfText_setString(ms->tnbscore, ms->nbscorestr);
					update_dice5(ms);
				}

				if (mp.x > 1458 && mp.x < 1617 && mp.y > 873 && mp.y < 928)
					sfRenderWindow_close(ms->window);
			}
			escape(ms->event, ms->window, ms);
		}
	}
	destroy(ms);
	return (0);
}
