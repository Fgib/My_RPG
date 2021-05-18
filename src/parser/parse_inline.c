/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pars_inline
*/

#include "my_rpg.h"

char *get_inline_content_u(char *start, char *end, char *buff, int len)
{
    int k = my_strlen(start);
    int j = 0;
    char *res = malloc(sizeof(char) * (len + 1));

    for (; my_strncmp(buff + k, end, my_strlen(end)); ++k, j++) {
        res[j] = buff[k];
        res[j + 1] = '\0';
        if (buff[k + 1] == '\0') {
            return "";
        }
    }
    return res;
}

char *get_inline_content(char **file, char *balise)
{
    char *start = my_sprintf("<%s>", balise);
    char *end = my_sprintf("</%s>", balise);
    char *res;
    if (file == NULL)
        return NULL;
    for (int i = 0; file[i] != NULL; ++i) {
        char *buff = sanitize_str(file[i]);
        int len = my_strlen(buff) - my_strlen(balise) * 2 - 5;
        if (my_strncmp(buff, start, my_strlen(start)) || len < 0) {
            free(buff);
            continue;
        }
        if (my_strcmp(res = get_inline_content_u(start, end, buff, len), "")) {
            my_free(2, start, end);
            return res;
        }
        my_free(2, buff, res);
    }
    res = my_strdup("");
    return res;
}

char *get_inline_ncontent(char **file, char *balise, int n)
{
    char *start = my_sprintf("<%s>", balise);
    char *end = my_sprintf("</%s>", balise);
    char *res;

    if (file == NULL)
        return NULL;
    for (int i = 0, v = 0; file[i] != NULL; ++i) {
        char *buff = sanitize_str(file[i]);
        int len = my_strlen(buff) - my_strlen(balise) * 2 - 5;
        if (my_strncmp(buff, start, my_strlen(start)) || len < 0)
            continue;
        v++;
        if (v <= n)
            continue;
        if (my_strcmp(res = get_inline_content_u(start, end, buff, len), "")) {
            my_free(2, start, end);
            return res;
        }
        my_free(2, buff, res);
    }
    return "";
}