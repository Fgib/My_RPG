/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** save_player
*/

#include "my_rpg.h"

int save_sessions(playersave_t *save)
{
    int fd;

    CLEARFILE(save->save);
    fd = open(save->save, O_WRONLY, O_TRUNC);
    if (fd < 0)
        return 0;
    save_player(save->save1, 0, fd);
    save_player(save->save2, 1, fd);
    save_player(save->save3, 2, fd);
    close(fd);
    return 1;
}

void save_player(player_t player, int nbr, int fd)
{
    char *start = my_sprintf("<player%i>\n", nbr);
    char *end = my_sprintf("</player%i>\n", nbr);

    write(fd, start, my_strlen(start));
    save_stats(player.stats, fd);
    save_inventory(player.inventory, fd);
    write(fd, end, my_strlen(end));
    my_free(2, start, end);
}

void save_stats(p_stat stats, int fd)
{
    char *buff = my_sprintf("\t\t<mspeed>%i</mspeed>\n\t\t<aspeed>%i</aspeed>"
    "\n\t\t<damage>%i</damage>\n\t\t<lvl>%i</lvl>\n\t\t<xp>%i</xp>\n",
    stats.mov_speed, stats.atk_speed, stats.damage,
    stats.level, stats.xp);

    write(fd, "\t<stats>\n", 9);
    write(fd, buff, my_strlen(buff));
    free(buff);
    write(fd, "\t</stats>\n", 10);
}

void save_inventory(slot_t *inv, int fd)
{
    write(fd, "\t<inventory>\n", 13);
    for (int i = 0; i < 36; ++i) {
        char *buff = my_sprintf("\t\t<slot>%i:%i</slot>\n", inv[i].item_id,
        inv[i].count);
        if (inv[i].item_id != -1)
            write(fd, buff, my_strlen(buff));
        free(buff);
    }
    write(fd, "\t</inventory>\n", 14);
}