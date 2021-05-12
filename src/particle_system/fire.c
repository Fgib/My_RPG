/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** fire
*/

#include "my_rpg.h"

void fire_animation(gen_t *prm)
{
    int step;
    if (prm->game.part_l[1].lifetime >= 0) {
        prm->game.part_l[1].lifetime +=
        prm->game.part_l[1].lifetime < 60 ? 1 : -75;
        step = (prm->game.part_l[1].lifetime - 20) / 3;
        sfSprite_setTextureRect(prm->game.part_l[1].core,
        get_intrect(step / 4 * 128, step % 4 * 128, 128, 128));
        DRAW_S(prm->game.part_l[1].core);
    }
}