/*
** EPITECH PROJECT, 2018
** yams
** File description:
** window.c
*/

#include "my.h"

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*buffer;
  int	i;

  buffer = malloc(sizeof(*buffer));
  buffer->pixels = malloc(width * height * 4 * sizeof(buffer->pixels));
  buffer->width = width;
  buffer->height = height;
  if (buffer->pixels == NULL)
    return (0);
  i = 0;
  while (i < width * height * 4)
    {
      buffer->pixels[i] = 0;
      i++;
    }
  return (buffer);
}

int	verif(sfRenderWindow *window)
{
  if (window == NULL)
    return (1);
}

sfRenderWindow	*create_window(char* name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  verif(window);
  return (window);
}

int	initialisation(t_mapsize *ms)
{
  ms->window = create_window("YAMS", SCREEN_WIDTH, SCREEN_HEIGHT);
  ms->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  ms->sprite = sfSprite_create();
  sfSprite_setTexture(ms->sprite, ms->texture, sfTrue);
  ms->structure = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  return (0);
}

int	escape(sfEvent event, sfRenderWindow *window, t_mapsize *ms)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(ms->window);
  if (ms->event.type == sfEvtClosed)
    sfRenderWindow_close(ms->window);
  return (0);
}
