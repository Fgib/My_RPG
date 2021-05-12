/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_utils
*/

#include "my_rpg.h"
#include "parser.h"

char **get_balise_content(char **file, char *balise)
{
    int i = 0;
    int j = 0;
    char **res;
    int len = balise_content_length(file, balise);
    char *start = my_sprintf("<%s>", balise);
    char *end = my_sprintf("</%s>", balise);
    if (file == NULL)
        return NULL;
    for (; file[i] != NULL && my_strcmp(sanitize_str(file[i]), start); ++i);

    if (file[i] == NULL || len == 0)
        return NULL;
    res = malloc(sizeof(char *) * (len + 1));
    if (len <= 0)
        return NULL;
    for (i++, j = 0; file[i] != NULL &&
        my_strcmp(sanitize_str(file[i]), end); ++i, j++)
        res[j] = my_sprintf("%s", file[i]);
    res[j] = NULL;
    return res;
}

char **get_nbalise_content(char **file, char *balise, int n)
{
    int i = 0;
    int j = 0;
    char **res;
    int len = balise_content_length(file, balise);
    char *start = my_sprintf("<%s>", balise);
    char *end = my_sprintf("</%s>", balise);

    for (int v = 0; file[i] != NULL && v <= n; ++i)
        v += (!my_strcmp(sanitize_str(file[i]), start)) ? 1 : 0;
    if (file[i] == NULL || len == 0)
        return NULL;
    res = malloc(sizeof(char *) * (len + 1));
    for (j = 0; file[i] != NULL &&
        my_strcmp(sanitize_str(file[i]), end); ++i, j++)
        res[j] = my_sprintf("%s", file[i]);
    res[j] = NULL;
    return res;
}

int balise_content_length(char **file, char *balise)
{
    int i = 0;
    int res = 0;
    char *b;
    char *start = my_sprintf("<%s>", balise);
    char *end = my_sprintf("</%s>", balise);

    if (file == NULL)
        return 0;
    for (; file[i] != NULL && my_strcmp(b = sanitize_str(file[i]), start); ++i)
        free(b);
    if (file[i] == NULL) {
        my_free(2, start, end);
        return 0;
    }
    res = i;
    for (; file[i] != NULL && my_strcmp(b = sanitize_str(file[i]), end); ++i)
        free(b);
    return (file[i] == NULL) ? 0 : i - res - 1;
}