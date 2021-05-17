/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** utils
*/

#include <stdlib.h>

int mstl(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *stad(char *str1, char *str2)
{
    int len1 = mstl(str1);
    int len2 = mstl(str2);
    char *str_result = malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0;

    for (; i < len1; i++)
        str_result[i] = str1[i];
    for (int j = 0; j < len2; i++, j++)
        str_result[i] = str2[j];
    str_result[i] = 0;
    return str_result;
}

char *cts(char c)
{
    char *res = malloc(sizeof(char) * 2);

    res[0] = c;
    res[1] = 0;
    return (res);
}