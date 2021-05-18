/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** usage
*/

#include "my_rpg.h"

int item_use(gen_t *prm, slot_t *item_slot)
{
    item_t item;
    if (item_slot->item_id < 0 || item_slot->item_id >= prm->item_count)
        return 0;
    item = prm->items[item_slot->item_id];
    if (get_int_data("consummable", item.data) == 1)
        item_slot->count --;
    if (item_slot->count <= 0)
        item_slot->item_id = -1;
    usage(prm, item.type);
    return 1;
}

void heal_player(gen_t *prm, player_t *ply, int hp)
{
    prm->game.part_l[0].lifetime = 0;
    ply->life = fmin(ply->life + hp, 100);
}

void usage(gen_t *prm, int type)
{
    switch (type) {
    case 666: prm->game.player->gmode = (prm->game.player->gmode) ? 0 : 1;
        break;
    case 420: prm->game.player->fly = (prm->game.player->fly) ? 0 : 1;
        break;
    case 0: heal_player(prm, prm->game.player, 30);
        break;
    default: break;
    }
}