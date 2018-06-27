/*
** EPITECH PROJECT, 2018
** yams
** File description:
** display_text.c
*/

#include "my.h"

int     update_pair(t_mapsize *ms)
{
	sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
				   ms->structure->width,
				   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->pair, NULL);
	sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     update_doublepair(t_mapsize *ms)
{
	sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
				   ms->structure->width,
				   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->doublepair, NULL);
	sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     update_three(t_mapsize *ms)
{
//      sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->three, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     update_four(t_mapsize *ms)
{
//      sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->four, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     update_full(t_mapsize *ms)
{
//      sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->full, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     update_straight(t_mapsize *ms)
{
//      sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->straight, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     update_yams(t_mapsize *ms)
{
//      sfRenderWindow_clear(ms->window, sfBlack);
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->yams, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
        return (0);
}

int     set_txt(t_mapsize *ms)
{
  sfFont        *font;

  ms->pospair.x = 850;
  ms->pospair.y = 655;
  ms->posdoublepair.x = 750;
  ms->posdoublepair.y = 655;
  ms->posthree.x = 580;
  ms->posthree.y = 655;
  ms->posfour.x = 590;
  ms->posfour.y = 655;
  ms->posfull.x = 680;
  ms->posfull.y = 655;
  ms->posstraight.x = 690;
  ms->posstraight.y = 655;
  ms->posyams.x = 800;
  ms->posyams.y = 655;
  font = sfFont_createFromFile("font/freeredlight.ttf");
  ms->pair = sfText_create();
  ms->doublepair = sfText_create();
  ms->three = sfText_create();
  ms->four = sfText_create();
  ms->full = sfText_create();
  ms->straight = sfText_create();
  ms->yams = sfText_create();
  sfText_setString(ms->pair, "PAIR");
  sfText_setString(ms->doublepair, "DOUBLE PAIR");
  sfText_setString(ms->three, "THREE OF A KIND");
  sfText_setString(ms->four, "FOUR OF A KIND");
  sfText_setString(ms->full, "FULL HOUSE");
  sfText_setString(ms->straight, "STRAIGHT");
  sfText_setString(ms->yams, "YAMS");
  sfText_setFont(ms->pair, font);
  sfText_setFont(ms->doublepair, font);
  sfText_setFont(ms->three, font);
  sfText_setFont(ms->four, font);
  sfText_setFont(ms->full, font);
  sfText_setFont(ms->straight, font);
  sfText_setFont(ms->yams, font);
  sfText_setCharacterSize(ms->pair, 100);
  sfText_setCharacterSize(ms->doublepair, 100);
  sfText_setCharacterSize(ms->three, 100);
  sfText_setCharacterSize(ms->four, 100);
  sfText_setCharacterSize(ms->full, 100);
  sfText_setCharacterSize(ms->straight, 100);
  sfText_setCharacterSize(ms->yams, 100);
  sfText_setPosition(ms->pair, ms->pospair);
  sfText_setPosition(ms->doublepair, ms->posdoublepair);
  sfText_setPosition(ms->three, ms->posthree);
  sfText_setPosition(ms->four, ms->posfour);
  sfText_setPosition(ms->full, ms->posfull);
  sfText_setPosition(ms->straight, ms->posstraight);
  sfText_setPosition(ms->yams, ms->posyams);
  return (0);
}

int     create_txt(t_mapsize *ms)
{
  sfColor       color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 255;
  set_txt(ms);
  sfText_setColor(ms->pair, color);
  sfText_setColor(ms->doublepair, color);
  sfText_setColor(ms->three, color);
  sfText_setColor(ms->four, color);
  sfText_setColor(ms->full, color);
  sfText_setColor(ms->straight, color);
  sfText_setColor(ms->yams, color);
  return (0);
}
