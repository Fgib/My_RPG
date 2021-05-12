/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** save_scenario
*/

#include "my_rpg.h"

int save(scenario_t *sce)
{
    int fd;
    char *temp = my_sprintf("<title>%s</title>\n", sce->name);

    CLEARFILE(sce->path);
    fd = open(sce->path, O_WRONLY, O_TRUNC);
    if (fd < 0)
        return 0;

    write(fd, temp, my_strlen(temp));
    save_positions(sce, fd);
    save_dictionnary(sce, fd);
    save_vmap(sce, fd);
    close(fd);
    return 1;
}

void save_interactable(scenario_t *sce, int fd)
{
    write(fd, "<interactable>\n", 15);
    for (int i = 0; i < sce->inter_count; ++i) {
        char *buff = my_sprintf("\t<object>\n\t\t<id>%i</id>"
        "\n\t\t<type>%i</type>\n\t\t<pos>%i:%i</pos>\n\t"
        "</object>\n", sce->inter[i].id, sce->inter[i].type,
        sce->inter[i].pos.x, sce->inter[i].pos.y);
        write(fd, buff, my_strlen(buff));
    }
    write(fd, "</interactable>\n", 16);
}

void save_positions(scenario_t *sce, int fd)
{
    write(fd, "<positions>\n", 12);
    if (sce->start.x >= 0 && sce->start.y >= 0) {
        char *buff = my_sprintf("\t<start>%i:%i</start>\n",
        sce->start.x, sce->start.y);
        write(fd, buff, my_strlen(buff));
    }
    write(fd, "</positions>\n", 13);
}

void save_dictionnary(scenario_t *sce, int fd)
{
    write(fd, "<dictionnary>\n", 14);
    for (int i = 0; i < sce->dic_count; ++i) {
        char *buff = my_sprintf("\t<enemy>\n\t\t<hp>%i</hp>"
        "\n\t\t<armor>%i</armor>\n\t\t<speed>%i</speed>\n\t\t"
        "<number>%i</number>\n\t\t<range>%i</range>\n\t\t"
        "<texture>%s</texture>\n\t\t<zone>%i</zone>\n\t"
        "</enemy>\n", sce->dictionnary[i].hp, sce->dictionnary[i].armor,
        sce->dictionnary[i].speed, sce->dictionnary[i].number,
        sce->dictionnary[i].range, sce->dictionnary[i].sp_path,
        sce->dictionnary[i].zone);
        write(fd, buff, my_strlen(buff));
    }
    write(fd, "</dictionnary>\n", 15);
}