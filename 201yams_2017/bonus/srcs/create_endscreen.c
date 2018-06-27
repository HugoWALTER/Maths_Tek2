/*
** EPITECH PROJECT, 2018
** yams
** File description:
** create_endscreen.c
*/

#include "my.h"

int     update_end(t_mapsize *ms)
{
	sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
				   ms->structure->width,
				   ms->structure->height, 0, 0);
	sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->tscore, NULL);
        sfRenderWindow_drawText(ms->window, ms->tnbscore, NULL);
	sfRenderWindow_drawText(ms->window, ms->exit, NULL);
	sfRenderWindow_display(ms->window);
	return (0);
}

int     set_end(t_mapsize *ms)
{
	sfFont        *font;

	ms->posexit.x = 1465;
	ms->posexit.y = 855;
	ms->posscore.x = 600;
        ms->posscore.y = 400;
        ms->posnbscore.x = 1200;
        ms->posnbscore.y = 400;
	sfText_setCharacterSize(ms->exit, 70);
	sfText_setCharacterSize(ms->tscore, 140);
	sfText_setCharacterSize(ms->tnbscore, 140);
	sfText_setPosition(ms->exit, ms->posexit);
	sfText_setPosition(ms->tscore, ms->posscore);
	sfText_setPosition(ms->tnbscore, ms->posnbscore);
	return (0);
}

int     draw_end(t_mapsize *ms)
{
	sfColor       color;
	sfColor       color2;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	color2.r = 14;
	color2.g = 75;
	color2.b = 93;
	color2.a = 255;
	set_end(ms);
	sfText_setColor(ms->exit, color);
	sfText_setColor(ms->tscore, color);
	sfText_setColor(ms->tnbscore, color2);
	return (0);
}

int     create_endscreen(t_mapsize *ms)
{
	draw_end(ms);
	return (0);
}
