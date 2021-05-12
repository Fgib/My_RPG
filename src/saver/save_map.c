/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** sav_map
*/

#include "my_rpg.h"

void save_vmap(scenario_t *sce, int fd)
{
    char *sizex = my_sprintf("\t<sizex>%i</sizex>\n", sce->mapsize.x);
    char *sizey = my_sprintf("\t<sizey>%i</sizey>\n", sce->mapsize.y);

    write(fd, "<map>\n", 6);
    write(fd, sizex, my_strlen(sizex));
    write(fd, sizey, my_strlen(sizey));
    for (int i = 0; i < sce->mapsize.y; ++i) {
        for (int j = 0; j < sce->mapsize.x; ++j) {
            save_map_block(sce, (vec_t){i, j}, fd);
        }
    }
    write(fd, "</map>\n", 7);
}

void save_map_block_writer(scenario_t *sce, vec_t coord, int fd, int k)
{
    char *temp;
    if (sce->vmap[coord.x][coord.y][k] == -1)
        temp = my_sprintf("\t<region>\n\t\t<id>-1</id>\n");
    else
        temp = my_sprintf("\t<region>\n\t\t<id>%i</id>\n",
        sce->vmap[coord.x][coord.y][k]);
    write(fd, temp, my_strlen(temp));
    free(temp);
    temp = my_sprintf("\t\t<coord>%i:%i:%i</coord>\n\t</region>\n",
    coord.x, coord.y, k);
    write(fd, temp, my_strlen(temp));
    free(temp);
}

void save_map_block(scenario_t *sce, vec_t coord, int fd)
{
    for (int k = 0; k < 4; ++k) {
        if (sce->vmap[coord.x][coord.y][k] != 0) {
            save_map_block_writer(sce, coord, fd, k);
        }
    }
}