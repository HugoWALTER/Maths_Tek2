/*
** EPITECH PROJECT, 2018
** yams
** File description:
** create_texture
*/

#include "my.h"

int     update_menu(t_mapsize *ms)
{
	sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
				   ms->structure->width,
				   ms->structure->height, 0, 0);
	sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->launch, NULL);
	sfRenderWindow_drawText(ms->window, ms->exit, NULL);
	sfRenderWindow_drawText(ms->window, ms->title, NULL);
	sfRenderWindow_display(ms->window);
	return (0);
}

int     set_menu(t_mapsize *ms)
{
  sfFont        *font;

  ms->poslaunch.x = 255;
  ms->poslaunch.y = 855;
  ms->posexit.x = 1465;
  ms->posexit.y = 855;
  ms->postitle.x = 750;
  ms->postitle.y = 355;
  font = sfFont_createFromFile("font/freeredlight.ttf");
  ms->launch = sfText_create();
  ms->exit = sfText_create();
  ms->title = sfText_create();
  sfText_setString(ms->launch, "LAUNCH");
  sfText_setString(ms->exit, "EXIT");
  sfText_setString(ms->title, "YAMS");
  sfText_setFont(ms->launch, font);
  sfText_setFont(ms->exit, font);
  sfText_setFont(ms->title, font);
  sfText_setCharacterSize(ms->launch, 70);
  sfText_setCharacterSize(ms->exit, 70);
  sfText_setCharacterSize(ms->title, 140);
  sfText_setPosition(ms->launch, ms->poslaunch);
  sfText_setPosition(ms->exit, ms->posexit);
  sfText_setPosition(ms->title, ms->postitle);
  return (0);
}

int     draw_menu(t_mapsize *ms)
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
  set_menu(ms);
  sfText_setColor(ms->launch, color);
  sfText_setColor(ms->exit, color);
  sfText_setColor(ms->title, color2);
  return (0);
}

int     create_textures(t_mapsize *ms)
{
  ms->tmenu = sfTexture_createFromFile("rsc/tapisvert.jpg", NULL);
  ms->smenu = sfSprite_create();
  ms->dicesong = sfMusic_createFromFile("audio/bruitde.ogg");
  sfMusic_setVolume(ms->dicesong, 100.0);
  sfSprite_setTexture(ms->smenu, ms->tmenu, sfTrue);
  sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
  sfRenderWindow_display(ms->window);
  draw_menu(ms);
  return (0);
}
