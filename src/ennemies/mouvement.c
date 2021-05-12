/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** mouvement
*/

#include "my_rpg.h"

sfVector2f get_enemy_vector(float angle)
{
    float ac = sinus(angle);
    float cb = sqrt(1 - pow(ac, 2));
    return (sfVector2f) {cb, ac};
}

float get_angle_to_player(gen_t *prm, enemy_t *self)
{
    float x = (prm->game.player->coo.x / 256) - self->pos.x / 256;
    float y = (prm->game.player->coo.y / 256) - self->pos.y / 256;
    float angle = atan2(y, x) * 180 / M_PI + 270;

    return angle;
}