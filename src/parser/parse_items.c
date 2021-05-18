/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_item
*/

#include "my_rpg.h"

int get_items(gen_t *prm)
{
    char *file = my_file_loader("configs/items.conf");
    char **items = my_str_splitter(file, '\n');
    free(file);
    if (items == NULL)
        return 0;
    char **dic = get_balise_content(items, "items");

    prm->item_count = 0;
    if (dic == NULL)
        return 0;
    for (int i = 0; 1; i++) {
        char **block = get_nbalise_content(dic, "item", i);
        if (block == NULL)
            break;
        fill_item(prm, block);
        free_2dchar(block);
    }
    free_2dchar(dic);
    free_2dchar(items);
    return 1;
}

void fill_item(gen_t *prm, char **block)
{
    char **arr = malloc(sizeof(char *) * 4);
    char **data = get_balise_content(block, "data");

    arr[0] = get_inline_content(block, "name");
    arr[1] = get_inline_content(block, "type");
    arr[2] = get_inline_content(block, "icon");
    arr[3] = NULL;

    item_t_push(&prm->items, &prm->item_count, (item_t){arr[0],
        my_getnbr(arr[1]), get_sprite(arr[2]), data});
    free_2dchar(arr);
}