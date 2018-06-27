/*
1;5003;0c** EPITECH PROJECT, 2018
** yams
** File description:
** create_dices
*/

#include "my.h"

int	fade_dices(t_mapsize *ms)
{
	sfColor		cde1 = sfSprite_getColor(ms->sde1);
	sfColor		cde2 = sfSprite_getColor(ms->sde2);
	sfColor		cde3 = sfSprite_getColor(ms->sde3);
	sfColor		cde4 = sfSprite_getColor(ms->sde4);
	sfColor		cde5 = sfSprite_getColor(ms->sde5);
	int		i = 0;

	cde1.a = 0;
	cde2.a = 0;
	cde3.a = 0;
	cde4.a = 0;
	cde5.a = 0;
	sfMusic_play(ms->dicesong);
	while (sfMusic_getStatus(ms->dicesong) != sfStopped);
	while (i != 255)
	{
		cde1.a += 1;
		cde2.a += 1;
		cde3.a += 1;
		cde4.a += 1;
		cde5.a += 1;
		sfSprite_setColor(ms->sde1, cde1);
		sfSprite_setColor(ms->sde2, cde2);
		sfSprite_setColor(ms->sde3, cde3);
		sfSprite_setColor(ms->sde4, cde4);
		sfSprite_setColor(ms->sde5, cde5);
		sfText_setColor(ms->tnbattempts, ms->color2);
		update_dice5(ms);
		i += 1;
	}//ajouter un peu plus de delay
	return (0);
}

int     update_dice5(t_mapsize *ms)
{
	sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
	sfRenderWindow_drawText(ms->window, ms->ttour, NULL);
	sfRenderWindow_drawText(ms->window, ms->tnbtour, NULL);
	sfRenderWindow_drawText(ms->window, ms->ton10, NULL);
	sfRenderWindow_drawText(ms->window, ms->tscore, NULL);
	sfRenderWindow_drawText(ms->window, ms->tnbscore, NULL);
	sfText_setString(ms->tnbattempts, ms->nbattemptsstr);
	sfRenderWindow_drawText(ms->window, ms->tattempts, NULL);
	if (ms->attempts > 0)
		sfRenderWindow_drawText(ms->window, ms->buttonreroll, NULL);
	sfText_setColor(ms->tnbattempts, ms->color2);
	sfRenderWindow_drawText(ms->window, ms->tnbattempts, NULL);
	if (ms->valtext == 1)
		sfRenderWindow_drawText(ms->window, ms->pair, NULL);
	if (ms->valtext == 2)
		sfRenderWindow_drawText(ms->window, ms->doublepair, NULL);
	if (ms->valtext == 3)
		sfRenderWindow_drawText(ms->window, ms->three, NULL);
	if (ms->valtext == 6)
		sfRenderWindow_drawText(ms->window, ms->four, NULL);
	if (ms->valtext == 4)
		sfRenderWindow_drawText(ms->window, ms->full, NULL);
	if (ms->valtext == 5)
		sfRenderWindow_drawText(ms->window, ms->straight, NULL);
	if (ms->valtext == 10)
		sfRenderWindow_drawText(ms->window, ms->yams, NULL);
	sfSprite_setPosition(ms->sde1, ms->posdice1);
	sfSprite_setPosition(ms->sde2, ms->posdice2);
	sfSprite_setPosition(ms->sde3, ms->posdice3);
	sfSprite_setPosition(ms->sde4, ms->posdice4);
	sfSprite_setPosition(ms->sde5, ms->posdice5);
	sfRenderWindow_drawSprite(ms->window, ms->sde1, NULL);
	sfRenderWindow_drawSprite(ms->window, ms->sde2, NULL);
	sfRenderWindow_drawSprite(ms->window, ms->sde3, NULL);
	sfRenderWindow_drawSprite(ms->window, ms->sde4, NULL);
	sfRenderWindow_drawSprite(ms->window, ms->sde5, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int	randomizer(void)
{
	int	ra = 0;

	ra = (rand() % 6) + 1;
	printf("de : %d\n", ra);//printf a suppr
	return (ra);
}

int	randomize_dices(t_mapsize *ms)
{
	srand(time(NULL));
	ms->randde1 = randomizer() - 1;
	ms->randde2 = randomizer() - 1;
	ms->randde3 = randomizer() - 1;
	ms->randde4 = randomizer() - 1;
	ms->randde5 = randomizer() - 1;
	srand(time(NULL));
	sfSprite_setTexture(ms->sde1, ms->tdices[ms->randde1], sfTrue);
	sfSprite_setTexture(ms->sde2, ms->tdices[ms->randde2], sfTrue);
	sfSprite_setTexture(ms->sde3, ms->tdices[ms->randde3], sfTrue);
	sfSprite_setTexture(ms->sde4, ms->tdices[ms->randde4], sfTrue);
	sfSprite_setTexture(ms->sde5, ms->tdices[ms->randde5], sfTrue);
	ms->de1 = ms->randde1 + 1;
	ms->de2 = ms->randde2 + 1;
	ms->de3 = ms->randde3 + 1;
	ms->de4 = ms->randde4 + 1;
	ms->de5 = ms->randde5 + 1;
	printf("de1: %d, de2: %d, de3: %d, de4: %d, de5: %d\n", ms->randde1, ms->randde2, ms->randde3, ms->randde4, ms->randde5);
	       return (0);
}

int	create_dices(t_mapsize *ms)
{
	ms->scaledice.x = 0.5;
	ms->scaledice.y = 0.5;
	ms->tdices = malloc(sizeof(sfTexture *) * 6);
	ms->posdice1.x = 100;
	ms->posdice1.y = 100;
	ms->posdice2.x = 450;
	ms->posdice2.y = 100;
	ms->posdice3.x = 800;
	ms->posdice3.y = 100;
	ms->posdice4.x = 1150;
	ms->posdice4.y = 100;
	ms->posdice5.x = 1500;
	ms->posdice5.y = 100;
	ms->tdices[0] = sfTexture_createFromFile("rsc/1.png", NULL);
	ms->tdices[1] = sfTexture_createFromFile("rsc/2.png", NULL);
	ms->tdices[2] = sfTexture_createFromFile("rsc/3.png", NULL);
	ms->tdices[3] = sfTexture_createFromFile("rsc/4.png", NULL);
	ms->tdices[4] = sfTexture_createFromFile("rsc/5.png", NULL);
	ms->tdices[5] = sfTexture_createFromFile("rsc/6.png", NULL);

	ms->sde1 = sfSprite_create();
	ms->sde2 = sfSprite_create();
	ms->sde3 = sfSprite_create();
	ms->sde4 = sfSprite_create();
	ms->sde5 = sfSprite_create();
	ms->sde6 = sfSprite_create();

	sfSprite_setPosition(ms->sde1, ms->posdice1);
	sfSprite_setPosition(ms->sde2, ms->posdice2);
	sfSprite_setPosition(ms->sde3, ms->posdice3);
	sfSprite_setPosition(ms->sde4, ms->posdice4);
	sfSprite_setPosition(ms->sde5, ms->posdice5);
	sfSprite_setPosition(ms->sde6, ms->posdice5);

	sfSprite_setScale(ms->sde1, ms->scaledice);
	sfSprite_setScale(ms->sde2, ms->scaledice);
	sfSprite_setScale(ms->sde3, ms->scaledice);
	sfSprite_setScale(ms->sde4, ms->scaledice);
	sfSprite_setScale(ms->sde5, ms->scaledice);
	sfSprite_setScale(ms->sde6, ms->scaledice);
	update_dice5(ms);
	return (0);
}
