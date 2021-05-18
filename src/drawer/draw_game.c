/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** draw_game
*/

#include "my_rpg.h"

void draw_game_inventory(gen_t *prm)
{
    DRAW_S(prm->game.inv_tansp->sprite);
    DRAW_S(prm->game.player->stats_icon);
    DRAW_T(prm->game.player->stats.atk_speed_t);
    DRAW_T(prm->game.player->stats.mov_speed_t);
    DRAW_T(prm->game.player->stats.damage_t);
    DRAW_T(prm->game.player->stats.level_t);
    DRAW_T(prm->game.player->stats.xp_t);
    for (int i = 0; i < 36; i++) {
        int id = prm->game.player->inventory[i].item_id;
        DRAW_S(prm->game.inv_btn[i]->sprite);
        if (id >= 0 && id < prm->item_count)
            DRAW_S(prm->game.player->inventory[i].item.icon);
    }
    for (int i = 0; i < 36; i++) {
        if (prm->game.player->inventory[i].count > 0) {
            sfText_setString(prm->game.inv_btn[i]->text,
            get_str(prm->game.player->inventory[i].count));
            DRAW_T(prm->game.inv_btn[i]->text);
        }
    }
}

void draw_game_toolbar(gen_t *prm)
{
    for (int i = 27; i < 36; i++) {
        DRAW_S(prm->game.inv_btn[i]->sprite);
        if (prm->game.player->inventory[i].item_id != -1)
            DRAW_S(prm->game.player->inventory[i].item.icon);
    }
}

void draw_lifebar(gen_t *prm)
{
    float size = prm->game.player->life / 100.0;

    sfSprite_setScale(prm->game.lifebar.bar, get_vector(size, 1));
    DRAW_S(prm->game.lifebar.bar);
    DRAW_S(prm->game.lifebar.frame);
}

void draw_game(gen_t *prm)
{
    sfRenderWindow_setView(prm->window, prm->game.rendering);
    sfView_setCenter(prm->game.rendering, prm->game.player->coo);
    print_scenario_map(prm);
    heal_animation(prm);
    fire_animation(prm);
    print_enemies(prm);
    sfRenderWindow_setView(prm->window, prm->game.interface);
    if (prm->game.g_status == PLAY) {
        draw_lifebar(prm);
        draw_game_toolbar(prm);
    }
    if (prm->game.g_status == INVENTORY) {
        draw_game_inventory(prm);
    }
}