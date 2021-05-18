/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_game2
*/

#include "my_rpg.h"

void game_attack_heal_inventory_event(gen_t *prm)
{
    if (prm->event.type == sfEvtKeyReleased) {
        if (prm->event.key.code == sfKeySpace) {
            prm->game.player->attack_id = 1;
        }
        if (prm->event.key.code == sfKeyM) {
            prm->game.player->attack_id = 1;
            prm->game.part_l[1].lifetime = 0;
            sfSprite_setPosition(prm->game.part_l[1].core,
            get_vector(prm->game.mouse_tile_pos.x * 256 - 50,
            prm->game.mouse_tile_pos.y * 256 - 50));
        }
        if (prm->event.key.code == sfKeyEscape)
            prm->game_step = PAUSE;
        if (prm->event.key.code == sfKeyE) {
            prm->game.g_status == PLAY ? game_re_up_inventory(prm) :
            game_re_down_inventory(prm);
            prm->game.g_status = prm->game.g_status == PLAY ? INVENTORY : PLAY;
        }
    }
}

void inv_event(gen_t *prm)
{
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum1)
        item_use(prm, &prm->game.player->inventory[27]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum2)
        item_use(prm, &prm->game.player->inventory[28]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum3)
        item_use(prm, &prm->game.player->inventory[29]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum4)
        item_use(prm, &prm->game.player->inventory[30]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum5)
        item_use(prm, &prm->game.player->inventory[31]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum6)
        item_use(prm, &prm->game.player->inventory[32]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum7)
        item_use(prm, &prm->game.player->inventory[33]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum8)
        item_use(prm, &prm->game.player->inventory[34]);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyNum9)
        item_use(prm, &prm->game.player->inventory[35]);
}

void game_events(gen_t *prm)
{
    game_engine_zoom(prm);
    game_get_mouse_pos(prm);
    game_attack_heal_inventory_event(prm);
    inv_event(prm);
    if (prm->game.g_status == INVENTORY)
        game_inventory_events(prm);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyI)
        add_item(prm, 0, 1);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyO)
        add_item(prm, 1, 1);
    if (prm->event.type == sfEvtKeyReleased && prm->event.key.code == sfKeyP)
        add_item(prm, 2, 1);
}