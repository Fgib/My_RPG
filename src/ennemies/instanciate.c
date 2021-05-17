/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** instanciate
*/

#include "my_rpg.h"

void load_enemies(scenario_t *sce)
{
    sce->enemies_count = 0;
    for (int i = 0; i < sce->dic_count; ++i) {
        for (int j = 1; j <= sce->dictionnary[i].number; ++j) {
            enemy_t_push(&sce->enemies, &sce->enemies_count,
            sce->dictionnary[i]);
        }
    }

    for (int i = 0; i < sce->enemies_count; ++i) {
        sce->enemies[i].sprite = get_sprite(sce->enemies[i].sp_path);
        set_random_pos(sce, &(sce->enemies[i]));
        sce->enemies[i].look_dir = 0;
        sfSprite_setScale(sce->enemies[i].sprite, get_vector(4, 4));
        sfSprite_setOrigin(sce->enemies[i].sprite, get_vector(24, 32));
    }
}

void set_random_pos(scenario_t *sce, enemy_t *en)
{
    while (1) {
        int x = random_gen(0, sce->mapsize.x - 1);
        int y = random_gen(0, sce->mapsize.y - 1);

        if (sce->vmap[y][x][3] == en->zone || (!en->zone &&
        sce->vmap[y][x][3] >= 0)) {
            en->pos = (sfVector2f){x * 256, y * 256};
            return;
        }
    }
}