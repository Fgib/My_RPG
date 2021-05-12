/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** animation
*/

#include "my_rpg.h"

void player_animation(gen_t *prm)
{
    prm->game.player->skin_id += prm->game.player->skin_id < 35 ? 1 : -35;
    if (!strokes_count(prm->keys)) {
        sfSprite_setTextureRect(prm->game.player->player_sheet,
        get_intrect(64 * prm->game.player->dir + 256, 0, 64, 64));
    } else {
        sfSprite_setTextureRect(prm->game.player->player_sheet,
        get_intrect(64 * prm->game.player->dir,
        prm->game.player->skin_id / 4 * 64, 64, 64));
    }
    if (prm->game.player->attack_id != 0) {
        prm->game.player->attack_id +=
        prm->game.player->attack_id < 41 ? 1 : -41;
        sfSprite_setTextureRect(prm->game.player->player_sheet,
        get_intrect(64 * prm->game.player->dir + 256,
        prm->game.player->attack_id / 6 * 64, 64, 64));
    }
}