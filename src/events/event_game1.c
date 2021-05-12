/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_game
*/

#include "my_rpg.h"

void game_re_up_inventory(gen_t *prm)
{
    for (int i = 0; i < 36; i++) {
        sfSprite_setPosition(prm->game.inv_btn[i]->sprite,
        get_vector(710 + i % 9 * 56,
        520 + i / 9 * 56 + (i / 9 == 3 ? 25 : 0)));
        sfSprite_setScale(prm->game.inv_btn[i]->sprite,
        get_vector(1, 1));
        if (prm->game.player->inventory[i].item_id < 0)
            continue;
        sfSprite_setPosition(prm->game.player->inventory[i].item.icon,
        get_vector(710 + i % 9 * 56,
        520 + i / 9 * 56 + (i / 9 == 3 ? 25 : 0)));
        sfSprite_setScale(prm->game.player->inventory[i].item.icon,
        get_vector(1, 1));
    }
}

void game_re_down_inventory(gen_t *prm)
{
    for (int i = 27; i < 36; i++) {
        sfSprite_setPosition(prm->game.inv_btn[i]->sprite,
        get_vector(585 + i % 9 * 84, 1000));
        sfSprite_setScale(prm->game.inv_btn[i]->sprite,
        get_vector(1.5, 1.5));
        if (prm->game.player->inventory[i].item_id < 0)
            continue;
        sfSprite_setPosition(prm->game.player->inventory[i].item.icon,
        get_vector(585 + i % 9 * 84, 1000));
        sfSprite_setScale(prm->game.player->inventory[i].item.icon,
        get_vector(1.5, 1.5));
    }
}

void game_inventory_events(gen_t *prm)
{
    for (int i = 0; i < 36; i++) {
        if (duoforce(prm->event, prm->game.inv_btn[i], 53))
            item_use(prm, &prm->game.player->inventory[i]);
    }

}

void game_get_mouse_pos(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseMoved)
        prm->game.last_mouse_pos = (vec_t){prm->event.mouseMove.x,
            prm->event.mouseMove.y};
    float tile_size = (float)(256) * powf(1.05, prm->game.zoom);
    prm->game.mouse_tile_pos.x = (prm->game.last_mouse_pos.x - 960 +
    prm->game.player->coo.x * powf(1.05, prm->game.zoom)) / tile_size;
    prm->game.mouse_tile_pos.y = (prm->game.last_mouse_pos.y - 540 +
    prm->game.player->coo.y * powf(1.05, prm->game.zoom)) / tile_size;
}