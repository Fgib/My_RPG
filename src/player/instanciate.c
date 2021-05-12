/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** instanciate
*/

#include "my_rpg.h"

void new_stats(player_t *ply)
{
    ply->stats.mov_speed = 1;
    ply->stats.atk_speed = 1;
    ply->stats.damage = 5;
    ply->stats.level = 1;
    ply->stats.xp = 0;
    ply->stats.xp_next = get_xp_for_level(2);
}

void new_player(player_t *ply)
{
    new_inventory(ply);
    new_stats(ply);
}