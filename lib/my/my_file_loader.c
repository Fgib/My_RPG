/*
** EPITECH PROJECT, 2021
** B-CPE-200-LYN-2-1-matchstick-florian.gibault
** File description:
** my_file_loader
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int my_strlen(char *str);
char *str_add(char *str1, char *str2);

int my_char_nbfind(char c, char *arr)
{
    int res = 0;

    for (int i = 0; arr[i]; ++i)
        res += (c == arr[i]) ? 1 : 0;
    return (res);
}

char *my_file_loader(char *path)
{
    struct stat f_stat;
    int buffsize;
    char *memory = malloc(sizeof(char));
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        memory[0] = '\0';
        return memory;
    }
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

    if (my_char_nbfind(sep, str) < 1) {
        tab[0] = str_add("", str);
        tab[1] = NULL;
        return tab;
    }
    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0, tpos = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            i++;
            tpos = 0;
            tab[++j] = malloc(sizeof(char) * my_strlen(str));
        }
        tab[j][tpos] = str[i];
        tpos++;
        tab[j][tpos] = 0;
    }
    tab[j + 1] = NULL;
    return tab;
}