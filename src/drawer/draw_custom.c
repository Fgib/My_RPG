/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** draw_custom
*/

#include "my_rpg.h"

void draw_custom(gen_t *prm)
{

    sfRenderWindow_drawSprite(prm->window, prm->custom.transp->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window, prm->custom.save->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->custom.save->text, NULL);
    sfRenderWindow_drawSprite(prm->window, prm->custom.expl, NULL);

    draw_slider(prm->window, prm->custom.red);
    draw_slider(prm->window, prm->custom.green);
    draw_slider(prm->window, prm->custom.blue);
}