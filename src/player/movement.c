/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** movement
*/

#include "my_rpg.h"

int can_move(gen_t *prm, int dir, float speed)
{
    sfVector2f pos = prm->game.player->coo;
    vec_t fpos;

    pos.y += (dir == 0 || dir == 7 || dir == 1) ? -speed :
    (dir == 3 || dir == 4 || dir == 5) ? speed : 0;
    pos.x += (dir == 1 || dir == 2 || dir == 3) ? speed :
    (dir == 5 || dir == 6 || dir == 7) ? -speed : 0;
    pos.x /= 256;
    pos.y /= 256;
    fpos = (vec_t){(int)pos.x, (int)pos.y};
    if (pos.x < 0 || pos.y < 0 || fpos.x > prm->game.scenario.mapsize.x ||
        fpos.y > prm->game.scenario.mapsize.y)
        return 0;
    if (prm->game.scenario.vmap[fpos.y][fpos.x][3] == -1 &&
        !prm->game.player->fly)
        return 0;
    return 1;
}

int diagonal_movement_bis(gen_t *prm)
{
    if (prm->keys.mv_down && prm->keys.mv_left && can_move(prm, 5, 5)) {
        prm->game.player->coo.x -= 3.56;
        prm->game.player->coo.y += 3.56;
        prm->game.player->dir = 1;
        return 1;
    }
    if (prm->keys.mv_left && prm->keys.mv_up && can_move(prm, 7, 5)) {
        prm->game.player->coo.x -= 3.56;
        prm->game.player->coo.y -= 3.56;
        prm->game.player->dir = 0;
        return 1;
    }
    return 0;
}

int diagonal_movement(gen_t *prm)
{
    if (prm->keys.mv_up && prm->keys.mv_right && can_move(prm, 1, 5)) {
        prm->game.player->coo.x += 3.56;
        prm->game.player->coo.y -= 3.56;
        prm->game.player->dir = 0;
        return 1;
    }
    if (prm->keys.mv_right && prm->keys.mv_down && can_move(prm, 3, 5)) {
        prm->game.player->coo.x += 3.56;
        prm->game.player->coo.y += 3.56;
        prm->game.player->dir = 3;
        return 1;
    }
    return diagonal_movement_bis(prm);
}

void regular_movement(gen_t *prm)
{
    if (prm->keys.mv_up && can_move(prm, 0, 5)) {
        prm->game.player->coo.y -= 5;
        prm->game.player->dir = 0;
    }
    if (prm->keys.mv_left && can_move(prm, 6, 5)) {
        prm->game.player->coo.x -= 5;
        prm->game.player->dir = 1;
    }
    if (prm->keys.mv_down && can_move(prm, 4, 5)) {
        prm->game.player->coo.y += 5;
        prm->game.player->dir = 2;
    }
    if (prm->keys.mv_right && can_move(prm, 2, 5)) {
        prm->game.player->coo.x += 5;
        prm->game.player->dir = 3;
    }
}

void player_movement(gen_t *prm)
{
    if (prm->game.player->attack_id || diagonal_movement(prm)) {
        sfSprite_setPosition(prm->game.player->player_sheet,
        prm->game.player->coo);
        return;
    }
    regular_movement(prm);
    sfSprite_setPosition(prm->game.player->player_sheet,
    prm->game.player->coo);
}