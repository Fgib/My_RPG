/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** window_creator
*/

#include "my_rpg.h"

sfRenderWindow *window_creator(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, \
    "My_RPG", sfTitlebar | sfClose, NULL);
    return (window);
}