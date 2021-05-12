/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** heal
*/

#include "my_rpg.h"

void heal_animation(gen_t *prm)
{
    int step;
    sfSprite_setPosition(prm->game.part_l[0].core,
    (sfVector2f){prm->game.player->coo.x - 197, prm->game.player->coo.y - 275});
    if (prm->game.part_l[0].lifetime >= 0) {
        prm->game.part_l[0].lifetime +=
        prm->game.part_l[0].lifetime < 60 ? 1 : -75;
        step = prm->game.part_l[0].lifetime / 3;
        sfSprite_setTextureRect(prm->game.part_l[0].core,
        get_intrect(step / 5 * 128, step % 5 * 128, 128, 128));
        DRAW_S(prm->game.part_l[0].core);
    }
}