/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** inventory
*/

#include "my_rpg.h"

int swap_item(gen_t *prm, int slotid, int toswap)
{
    slot_t *inv = prm->game.player->inventory;
    slot_t slotswap = inv[toswap + 27];

    if (inv[slotid].item_id == -1)
        return 0;
    if (slotid >= 27 && toswap == 9) {
        if (!add_item(prm, prm->game.player->inventory[slotid].item_id,
            prm->game.player->inventory[slotid].count))
            return 0;
        prm->game.player->inventory[slotid].item_id = -1;
        prm->game.player->inventory[slotid].count = 0;
        return 1;
    }
    prm->game.player->inventory[toswap + 27] =
    prm->game.player->inventory[slotid];
    prm->game.player->inventory[slotid] = slotswap;
    return 1;
}

int have_item(player_t *ply, int id)
{
    for (int i = 0; i < 36; i++)
        if (ply->inventory[i].item_id == id)
            return i;
    return -1;
}

void new_inventory(player_t *ply)
{
    ply->inventory = malloc(sizeof(slot_t) * 36);
    for (int i = 0; i < 36; i++) {
        ply->inventory[i].item_id = -1;
        ply->inventory[i].count = 0;
    }
}