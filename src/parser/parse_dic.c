/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_dic
*/

#include "my_rpg.h"

int get_dictionnary(scenario_t *sce)
{
    char **dic = get_balise_content(sce->row_data, "dictionnary");

    sce->dic_count = 0;
    if (dic == NULL)
        return 0;
    for (int i = 0; 1; i++) {
        char **block = get_nbalise_content(dic, "enemy", i);
        if (block == NULL)
            break;
        fill_dic(sce, block);
        free_2dchar(block);
    }
    free_2dchar(dic);
    return 1;
}

void fill_dic(scenario_t *sce, char **block)
{
    char **arr = malloc(sizeof(char *) * 8);

    arr[0] = get_inline_content(block, "hp");
    arr[1] = get_inline_content(block, "range");
    arr[2] = get_inline_content(block, "armor");
    arr[3] = get_inline_content(block, "speed");
    arr[4] = get_inline_content(block, "number");
    arr[5] = get_inline_content(block, "texture");
    arr[6] = get_inline_content(block, "zone");
    arr[7] = NULL;
    enemy_t_push(&sce->dictionnary, &sce->dic_count,
    ((enemy_t){(sfVector2f){0, 0}, 0, my_getnbr(arr[0]),
        my_getnbr(arr[2]), my_getnbr(arr[1]),
        my_getnbr(arr[3]), my_getnbr(arr[4]),
        my_getnbr(arr[6]), 0, arr[5], NULL, 0}));
}