/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** file_loading
*/

#include "my_rpg.h"

char *my_file_loader(char *path)
{
    struct stat f_stat;
    int buffsize;
    char *memory;
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return "";
    stat(path, &f_stat);
    buffsize = f_stat.st_size;
    memory = malloc(sizeof(char) * (buffsize + 1));
    read(fd, memory, buffsize);
    memory[buffsize] = '\0';
    close(fd);
    return (memory);
}

char **my_str_splitter(char *str, char sep)
{
    char **tab = malloc(sizeof(char *) * (my_char_nbfind(sep, str) + 2));
    int j = 0;

    if (!my_strcmp(str, ""))
        return NULL;
    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0, tpos = 0; str[i] != '\0'; i++) {
        if (str[i] == sep && str[i + 1] != '\0') {
            tab[j][tpos] = '\0';
            tpos = 0;
            tab[++j] = malloc(sizeof(char) * my_strlen(str));
            tab[j][tpos] = '\0';
        } else if (str[i] != sep) {
            tab[j][tpos] = str[i];
            tpos++;
            tab[j][tpos] = 0;
        }
    }
    tab[j + 1] = NULL;
    return tab;
}

int check_file(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd >= 0)
        close(fd);
    return (fd < 0) ? 0 : 1;
}