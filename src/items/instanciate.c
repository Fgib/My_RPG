/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** instanciate
*/

#include "my_rpg.h"

void item_t_push(item_t **array, int *size, item_t new)
{
    item_t *buff = malloc(sizeof(**array) * ((*size) + 1));
    int i;
    for (i = 0; i < (*size); ++i)
        buff[i] = (*array)[i];
    buff[i] = new;
    if (*size)
        free(*array);
    *array = buff;
    (*size)++;
}

item_t get_item_by_id(item_t *items, int id)
{
    item_t item = items[id];
    return item;
}

int check_for_slot(gen_t *prm, int id, int nbr)
{
    for (int i = 0; i < 36; ++i) {
        if ((prm->game.player->inventory[i].item_id < 0 ||
        prm->game.player->inventory[i].item_id == id) &&
        prm->game.player->inventory[i].count < 64) {
            prm->game.player->inventory[i].item = prm->items[id];
            prm->game.player->inventory[i].item.icon =
            sfSprite_copy(prm->game.player->inventory[i].item.icon);
            prm->game.player->inventory[i].item_id = id;
            prm->game.player->inventory[i].count+= nbr;
            sfSprite_setPosition(prm->game.player->inventory[i].item.icon,
            get_vector(710 + i % 9 * 56, 520 +
            i / 9 * 56 + (i / 9 == 3 ? 25 : 0)));
            sfSprite_setScale(prm->game.player->inventory[i].item.icon,
            get_vector(1, 1));
            prm->game.g_status == PLAY ? game_re_down_inventory(prm) : (void)1;
            return 1;
        }
    }
    return 0;
}

int add_item(gen_t *prm, int id, int nbr)
{
    int sid = have_item(prm->game.player, id);

    if (sid != -1 && prm->game.player->inventory[sid].count < 64) {
        prm->game.player->inventory[sid].count+= nbr;
        return 1;
    }
    return check_for_slot(prm, id, nbr);
}