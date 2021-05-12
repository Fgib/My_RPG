/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_inter
*/

#include "my_rpg.h"

int get_interactable(scenario_t *sce)
{
    char **dic = get_balise_content(sce->row_data, "interactable");

    sce->inter_count = 0;
    if (dic == NULL)
        return 0;
    for (int i = 0; 1; i++) {
        char **block = get_nbalise_content(dic, "object", i);
        if (block == NULL)
            break;
        fill_interactable(sce, block);
        free_2dchar(block);
    }
    free_2dchar(dic);
    return 1;
}

void fill_interactable(scenario_t *sce, char **block)
{
    char **arr = malloc(sizeof(char *) * 4);
    char **pos;

    arr[0] = get_inline_content(block, "id");
    arr[1] = get_inline_content(block, "type");
    arr[2] = get_inline_content(block, "pos");
    arr[3] = NULL;
    pos = my_str_splitter(arr[2], ':');

    interactable_t_push(&sce->inter, sce->inter_count,
    ((interactable_t){my_getnbr(arr[0]), my_getnbr(arr[1]),
        (vec_t){my_getnbr(pos[0]), my_getnbr(pos[1])}}));
}