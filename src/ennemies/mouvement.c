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
    float cb = sqrt(1 - pow(ac, 2))  * ((angle < 270 && angle > 90) ? -1 : 1);
    return (sfVector2f) {cb, ac};
}

float get_angle_to_player(gen_t *prm, enemy_t *self)
{
    float x = ( self->pos.x / 256) - prm->game.player->coo.x / 256;
    float y = (self->pos.y / 256) - prm->game.player->coo.y / 256;
    float angle = atan2(y, x) * 180 / M_PI + 180;

    return angle;
}

void enemies_movement(gen_t *prm)
{
    float angle;
    sfVector2f mov;

    for (int i = 0; i < prm->game.scenario.enemies_count; i++) {
        if (RANGE(prm->game.scenario.enemies[i].pos, prm->game.player->coo) < 3) {
            angle = get_angle_to_player(prm, &prm->game.scenario.enemies[i]);
            mov = get_enemy_vector(angle);
            ADD_VEC(prm->game.scenario.enemies[i].pos, mov.x * (2 + prm->game.scenario.enemies[i].speed), mov.y * (2 + prm->game.scenario.enemies[i].speed))
            SPOSE(prm->game.scenario.enemies[i])
        }
        if (PRANGE(prm->game.scenario.enemies[i].pos, prm->game.player->coo) < 100) {
            prm->game.player->life = fmax(prm->game.player->life - 0.1, 0);
            printf("new life: %f\n", prm->game.player->life);
        }
    }
}