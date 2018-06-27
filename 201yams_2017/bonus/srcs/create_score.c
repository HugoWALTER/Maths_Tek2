/*
** EPITECH PROJECT, 2018
** yams
** File description:
** create_score.c
*/

#include "my.h"

char    *int_to_string(int i, char *b)
{
        char const digit[] = "o123456789";
        char    *p = b;
        if(i < 0)
        {
                *p++ = '-';
                i *= -1;
        }
        int shifter = i;
        do
        {
                ++p;
                shifter = shifter/10;
        } while (shifter);
        *p = '\0';
        do
        {
                *--p = digit[i%10];
                i = i/10;
        } while(i);
        return b;
}

int	update_tour(t_mapsize *ms)
{
        sfTexture_updateFromPixels(ms->tmenu, ms->structure->pixels,
                                   ms->structure->width,
                                   ms->structure->height, 0, 0);
        sfRenderWindow_drawSprite(ms->window, ms->smenu, NULL);
	sfRenderWindow_drawText(ms->window, ms->ttour, NULL);
	sfRenderWindow_drawText(ms->window, ms->tnbtour, NULL);
	sfRenderWindow_drawText(ms->window, ms->ton10, NULL);
	sfRenderWindow_drawText(ms->window, ms->tscore, NULL);
	sfRenderWindow_drawText(ms->window, ms->tattempts, NULL);
	sfRenderWindow_drawText(ms->window, ms->tnbattempts, NULL);
	sfRenderWindow_drawText(ms->window, ms->buttonreroll, NULL);
        sfRenderWindow_drawText(ms->window, ms->launch, NULL);
        sfRenderWindow_drawText(ms->window, ms->exit, NULL);
        sfRenderWindow_display(ms->window);
}

int     set_tour(t_mapsize *ms)
{
	sfFont        *font;

	ms->nbtourstr = malloc(sizeof(char) * 100);
	ms->nbtourstr = int_to_string(ms->tour, ms->nbtourstr);
	ms->nbscorestr = malloc(sizeof(char) * 100);
	ms->nbscorestr = int_to_string(ms->score, ms->nbscorestr);
	ms->nbattemptsstr = malloc(sizeof(char) * 100);
	ms->nbattemptsstr = int_to_string(ms->attempts, ms->nbattemptsstr);
	printf("nb tour: %d\n tour en string: %s\n", ms->tour, ms->nbtourstr);
	ms->postour.x = 690;
	ms->postour.y = 0;
	ms->posnbtour.x = 900;
	ms->posnbtour.y = 0;
	ms->poson10.x = 980;
	ms->poson10.y = 0;
	ms->posscore.x = 1400;
	ms->posscore.y = 0;
	ms->posnbscore.x = 1700;
	ms->posnbscore.y = 0;
  	ms->posattempts.x = 155;
	ms->posattempts.y = 500;
	ms->posnbattempts.x = 555;
	ms->posnbattempts.y = 480;
	ms->posreroll.x = 265;
	ms->posreroll.y = 680;
	font = sfFont_createFromFile("font/freeredlight.ttf");
	ms->ttour = sfText_create();
	ms->tnbtour = sfText_create();
	ms->ton10 = sfText_create();
	ms->tscore = sfText_create();
	ms->tnbscore = sfText_create();
	ms->tattempts = sfText_create();
	ms->tnbattempts = sfText_create();
	ms->buttonreroll = sfText_create();
	sfText_setString(ms->ttour, "TOUR");
	sfText_setString(ms->tnbtour, ms->nbtourstr);
	sfText_setString(ms->ton10, "sur 1o");
	sfText_setString(ms->tscore, "SCORE");
	sfText_setString(ms->tnbscore, ms->nbscorestr);
	sfText_setString(ms->tattempts, "ATTEMPTS");
	sfText_setString(ms->tnbattempts, ms->nbattemptsstr);
	sfText_setString(ms->buttonreroll, "RE ROLL");
	sfText_setFont(ms->ttour, font);
	sfText_setFont(ms->tnbtour, font);
	sfText_setFont(ms->ton10, font);
	sfText_setFont(ms->tscore, font);
	sfText_setFont(ms->tnbscore, font);
	sfText_setFont(ms->tattempts, font);
	sfText_setFont(ms->tnbattempts, font);
	sfText_setFont(ms->buttonreroll, font);
	sfText_setCharacterSize(ms->ttour, 70);
	sfText_setCharacterSize(ms->tnbtour, 70);
	sfText_setCharacterSize(ms->ton10, 70);
	sfText_setCharacterSize(ms->tscore, 70);
	sfText_setCharacterSize(ms->tnbscore, 70);
	sfText_setCharacterSize(ms->tattempts, 70);
	sfText_setCharacterSize(ms->tnbattempts, 90);
	sfText_setCharacterSize(ms->buttonreroll, 70);
	sfText_setPosition(ms->ttour, ms->postour);
	sfText_setPosition(ms->tnbtour, ms->posnbtour);
	sfText_setPosition(ms->ton10, ms->poson10);
	sfText_setPosition(ms->tscore, ms->posscore);
	sfText_setPosition(ms->tnbscore, ms->posnbscore);
	sfText_setPosition(ms->tattempts, ms->posattempts);
	sfText_setPosition(ms->tnbattempts, ms->posnbattempts);
	sfText_setPosition(ms->buttonreroll, ms->posreroll);
	return (0);
}

int     create_tour(t_mapsize *ms)
{
  sfColor       color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 255;
  ms->color2.r = 255;
  ms->color2.g = 0;
  ms->color2.b = 0;
  ms->color2.a = 255;
  set_tour(ms);
  sfText_setColor(ms->ttour, color);
  sfText_setColor(ms->tnbtour, color);
  sfText_setColor(ms->ton10, color);
  sfText_setColor(ms->tscore, color);
  sfText_setColor(ms->tnbscore, color);
  sfText_setColor(ms->tattempts, color);
  sfText_setColor(ms->tnbattempts, ms->color2);
  sfText_setColor(ms->buttonreroll, color);
  return (0);
}
