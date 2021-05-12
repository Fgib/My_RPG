/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** string_stuff3
*/

#include "my_rpg.h"

char *str_add(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *str_result = malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0;

    for (; i < len1; i++) {
        str_result[i] = str1[i];
    }
    for (int j = 0; j < len2; i++, j++) {
        str_result[i] = str2[j];
    }
    str_result[i] = 0;
    return str_result;
}

char *sanitize_str(char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);
    int j = 0;
    int i = 0;

    for (j = 0, i = 0; str[i] != '\0'; ++i, ++j) {
        if (my_char_nbfind(str[i], "\n\t "))
            j--;
        else
            res[j] = str[i];
    }
    res[j] = '\0';
    return res;
}