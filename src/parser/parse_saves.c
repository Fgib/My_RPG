/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** parse_saves
*/

#include "my_rpg.h"


int get_saves(gen_t *prm)
{
    char **file = my_str_splitter(my_file_loader(prm->saves.save), '\n');
    char **save0 = get_balise_content(file, "player0");
    char **save1 = get_balise_content(file, "player1");
    char **save2 = get_balise_content(file, "player2");

    if (fill_player(prm, &prm->saves.save1, save0))
        free_2dchar(save0);
    if (fill_player(prm, &prm->saves.save2, save1))
        free_2dchar(save1);
    if (fill_player(prm, &prm->saves.save3, save2))
        free_2dchar(save2);
    return 1;
}

void fill_stats(player_t *ply, char **stats)
{
    char **arr = malloc(sizeof(char *) * 6);

    arr[0] = get_inline_content(stats, "mspeed");
    arr[1] = get_inline_content(stats, "aspeed");
    arr[2] = get_inline_content(stats, "damage");
    arr[3] = get_inline_content(stats, "lvl");
    arr[4] = get_inline_content(stats, "xp");
    arr[5] = NULL;
    ply->stats.mov_speed = my_getnbr(arr[0]);
    ply->stats.atk_speed = my_getnbr(arr[1]);
    ply->stats.damage = my_getnbr(arr[2]);
    ply->stats.level = my_getnbr(arr[3]);
    ply->stats.xp = my_getnbr(arr[4]);
    ply->stats.xp_next = get_xp_for_level(ply->stats.level + 1);
}

void fill_inv(gen_t *prm, player_t *ply, char **inv)
{
    char *buff;
    char **temp;
    for (int i = 0, slot = 0;;) {
        buff = get_inline_ncontent(inv, "slot", i);
        temp = my_str_splitter(buff, ':');
        if (!my_strcmp(buff, ""))
            break;
        if (my_getnbr(temp[1]) >= 0 && my_getnbr(temp[1]) < prm->item_count) {
            slot = my_getnbr(temp[0]);
            ply->inventory[slot].item = prm->items[my_getnbr(temp[1])];
            SFDP(ply->inventory[slot].item.icon);
            ply->inventory[slot].item_id = my_getnbr(temp[1]);
            ply->inventory[slot].count+= my_getnbr(temp[2]);
            SPOSI(ply->inventory[slot].item.icon, slot);
            sfSprite_setScale(ply->inventory[slot].item.icon, GV(1, 1));
        }
        free(buff);
        free_2dchar(temp);
        ++i;
    }
}

int fill_player(gen_t *prm, player_t *ply, char **block)
{
    char **stats = get_balise_content(block, "stats");
    char **inv = get_balise_content(block, "inventory");

    if (block == NULL) {
        new_player(ply);
        return 0;
    }
    (stats == NULL) ? new_stats(ply) : fill_stats(ply, stats);
    new_inventory(ply);
    if (inv != NULL)
        fill_inv(prm, ply, inv);
    return 1;
}