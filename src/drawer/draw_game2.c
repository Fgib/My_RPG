/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** draw_game
*/

#include "my_rpg.h"

void print_scenario_map_insider(gen_t *prm, int j, int k)
{
    sfVector2f coo = prm->game.player->coo;
    float vis = prm->game.player->vision;
    if (sqrt(pow(coo.x / 256 - j, 2) + pow(coo.y / 256 - k, 2)) > vis + 1)
        return;
    if (sqrt(pow(coo.x / 256 - j, 2) + pow(coo.y / 256 - k, 2)) > vis) {
        for (int i = 0; i < 3; ++i)
            sfSprite_setColor(prm->game.scenario.spmap[k][j][i],
            (sfColor){100, 100, 100, 255});
    } else
        for (int i = 0; i < 3; ++i)
            sfSprite_setColor(prm->game.scenario.spmap[k][j][i],
            (sfColor){255, 255, 255, 255});
    for (int i = 0; i < 3; ++i)
        DRAW_S(prm->game.scenario.spmap[k][j][i]);
}

void print_scenario_map(gen_t *prm)
{
    for (int j = 0; j < prm->game.scenario.mapsize.x; j++) {
        for (int k = 0; k < prm->game.scenario.mapsize.y; ++k) {
            print_scenario_map_insider(prm, j, k);
        }
    }
}

void print_enemies(gen_t *prm)
{
    sfVector2f coo = prm->game.player->coo;
    float vis = prm->game.player->vision;
    for (int i = 0; i < prm->game.scenario.enemies_count; ++i) {
        if (RANGE(coo, prm->game.scenario.enemies[i].pos) > vis + 1)
            continue;
        if (RANGE(coo, prm->game.scenario.enemies[i].pos) > vis)
            SCOL(prm->game.scenario.enemies[i].sprite, 100, 100, 100, 255);
        else
            SCOL(prm->game.scenario.enemies[i].sprite, 255, 255, 255, 255);
        enemies_animation(&prm->game.scenario.enemies[i], 45);
        SPOSE(prm->game.scenario.enemies[i]);
    }
    for (int i = 0; i < prm->game.scenario.enemies_count; ++i)
        if (prm->game.player->coo.y > prm->game.scenario.enemies[i].pos.y)
            DRAW_S(prm->game.scenario.enemies[i].sprite);
    DRAW_S(prm->game.player->player_sheet);
    for (int i = 0; i < prm->game.scenario.enemies_count; ++i)
        if (prm->game.player->coo.y <= prm->game.scenario.enemies[i].pos.y)
            DRAW_S(prm->game.scenario.enemies[i].sprite);
}

void print_interactable(gen_t *prm)
{
    for (int i = 0; i < prm->game.scenario.inter_count; ++i) {
        sfRenderWindow_drawSprite(prm->window,
        prm->game.scenario.inter[i].sprite, NULL);
    }
}