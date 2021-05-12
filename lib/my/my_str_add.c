/*
** EPITECH PROJECT, 2021
** B-CPE-200-LYN-2-1-matchstick-florian.gibault
** File description:
** my_str_add
*/

#include <stdlib.h>

int my_strlen(char *str);

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