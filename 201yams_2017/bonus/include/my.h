/*
** EPITECH PROJECT, 2018
** yams
** File description:
** my.h
*/

#ifndef MY_H
# define MY_H
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

typedef struct  s_my_framebuffer
{
	sfUint8		*pixels;
	int		width;
	int		height;
}               t_my_framebuffer;

typedef struct  s_mapsize
{
	sfRenderWindow		*window;
	sfEvent			event;
	sfTexture		*texture;
	sfSprite		*sprite;
	t_my_framebuffer	*structure;
	sfVector2i		mapSize;
	sfMusic			*music;
	sfTexture		*tmenu;
	sfSprite		*smenu;
	sfText			*launch;
	sfVector2f		poslaunch;
	sfText			*exit;
	sfVector2f		posexit;
	sfText			*title;
	sfVector2f		postitle;
	sfText			*pair;
	sfVector2f		pospair;
	sfText			*doublepair;
	sfVector2f		posdoublepair;
	sfText			*three;
	sfVector2f		posthree;
	sfText			*four;
	sfVector2f		posfour;
	sfText			*full;
	sfVector2f		posfull;
	sfText			*straight;
	sfVector2f		posstraight;
	sfText			*yams;
	sfVector2f		posyams;
	sfTexture		**tdices;
	sfVector2f		posdice1;
	sfVector2f		posdice2;
	sfVector2f		posdice3;
	sfVector2f		posdice4;
	sfVector2f		posdice5;
	sfVector2f		posdice6;
	sfVector2f		scaledice;
	int			randde1;
	int			randde2;
	int			randde3;
	int			randde4;
	int			randde5;
	sfSprite		*sde1;
	sfSprite		*sde2;
	sfSprite		*sde3;
	sfSprite		*sde4;
	sfSprite		*sde5;
	sfSprite		*sde6;
	int			de1;
	int			de2;
	int			de3;
	int			de4;
	int			de5;
	int			tour;
	sfText			*ttour;
	sfText			*tnbtour;
	sfText			*ton10;
	sfVector2f		postour;
	sfVector2f		posnbtour;
	sfVector2f		poson10;
	char			*nbtourstr;
	int			score;
	int			scoretemp;
	int			update;
	sfText			*tscore;
	sfVector2f		posscore;
	sfText			*tnbscore;
	sfVector2f		posnbscore;
	char			*nbscorestr;
	int			attempts;
	sfText			*tattempts;
	sfVector2f		posattempts;
	sfText			*tnbattempts;
	sfVector2f		posnbattempts;
	sfText			*buttonreroll;
	sfVector2f		posreroll;
	char			*nbattemptsstr;
	sfColor			color2;
	sfMusic			*dicesong;
	int			valtext;
	int			valalgo;
	int			lastscore;
}               t_mapsize;

t_my_framebuffer*	my_framebuffer(int width, int height);
int			verif(sfRenderWindow *window);
sfRenderWindow		*create_window(char *name, int width, int height);
int			initialisation(t_mapsize *ms);
int			escape(sfEvent event, sfRenderWindow *window,
			       t_mapsize *ms);
void			update_texture(t_mapsize *ms);
sfVector2f		controls_updown(sfVector2f pos, float direction,
					t_mapsize *ms);
int			main(int ac, char **av);
t_mapsize		*init_struct(t_mapsize *mapsize);
void			my_put_pixel(t_my_framebuffer* framebuffer, int x,
				     int y, sfColor color);
void			destroy(t_mapsize *ms);
int			create_textures(t_mapsize *ms);
int			update_menu(t_mapsize *ms);
int			create_txt(t_mapsize *ms);
int			update_pair(t_mapsize *ms);
int			create_dices(t_mapsize *ms);
int			update_dice1(t_mapsize *ms);
int			update_dice2(t_mapsize *ms);
int			update_dice3(t_mapsize *ms);
int			update_dice4(t_mapsize *ms);
int			update_dice5(t_mapsize *ms);
int			fade_dices(t_mapsize *ms);
int			randomize_dices(t_mapsize *ms);
int			create_tour(t_mapsize *ms);
int			set_tour(t_mapsize *ms);
int			update_end(t_mapsize *ms);
int			create_endscreen(t_mapsize *ms);
int			find_pair(int *tab, t_mapsize *ms);
int			my_algo(t_mapsize *ms);

#endif /* !MY_H */
