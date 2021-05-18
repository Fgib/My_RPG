/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_map
*/

#include "my_rpg.h"

vec_t get_map_size(char **file)
{
    vec_t res = (vec_t){-1, -1};
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = get_inline_content(file, "sizex");
    pos[1] = get_inline_content(file, "sizey");
    pos[2] = NULL;
    if (my_strcmp(pos[0], ""))
        res.x = my_getnbr(pos[0]);
    if (my_strcmp(pos[1], ""))
        res.y = my_getnbr(pos[1]);
    free_2dchar(pos);
    return res;
}

int get_start(scenario_t *sce, char **pos)
{
    char **temp;
    char *buff = get_inline_content(pos, "start");

    if (!my_strcmp(buff, "")) {
        sce->start = (vec_t){-1, -1};
        return 0;
    }
    temp = my_str_splitter(buff, ':');
    sce->start = (vec_t) {my_getnbr(temp[0]), my_getnbr(temp[1])};
    free(buff);
    free_2dchar(temp);
    return 1;
}

int get_end(scenario_t *sce, char **pos)
{
    char **temp;
    char *buff = get_inline_content(pos, "end");

    if (!my_strcmp(buff, "")) {
        sce->end = (vec_t){-1, -1};
        return 0;
    }
    temp = my_str_splitter(buff, ':');
    sce->end = (vec_t) {my_getnbr(temp[0]), my_getnbr(temp[1])};
    free(buff);
    free_2dchar(temp);
    return 1;
}

int get_positions(scenario_t *sce)
{
    char **pos = get_balise_content(sce->row_data, "positions");

    if (pos == NULL) {
        sce->start = (vec_t){-1, -1};
        sce->end = (vec_t){-1, -1};
        return 0;
    }
    get_start(sce, pos);
    get_end(sce, pos);
    return 1;
}

int get_map(gen_t *prm, scenario_t *sce)
{
    char **map = get_balise_content(sce->row_data, "map");
    if (map == NULL)
        return 0;
    sce->mapsize = get_map_size(map);
    if (sce->mapsize.x == -1 || sce->mapsize.y == -1)
        return 0;
    sce->vmap = malloc(sizeof(int **) * sce->mapsize.y);
    sce->spmap = malloc(sizeof(sfSprite ***) * sce->mapsize.y);
    for (int i = 0; i < sce->mapsize.y; ++i) {
        sce->vmap[i] = malloc(sizeof(int *) * sce->mapsize.x);
        sce->spmap[i] = malloc(sizeof(sfSprite **) * sce->mapsize.x);
        for (int v = 0; v < sce->mapsize.x; ++v) {
            sce->vmap[i][v] = malloc(sizeof(int) * 4);
            sce->spmap[i][v] = malloc(sizeof(sfSprite *) * 4);
            setup_map(prm, sce, i, v);
        }
    }
    fill_map(sce, map);
    reload_spmap(prm, sce);
    return 1;
}