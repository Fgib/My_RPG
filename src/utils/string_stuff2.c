/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** lib_func
*/

#include "my_rpg.h"

int my_getnbr(char *str)
{
    long nbr = 0;
    int neg = 0;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            neg++;
    }
    for (; str[i] >= 48 && str[i] <= 57; i++) {
        nbr *= 10;
        nbr += (str[i] - 48);
        if (nbr > 2147483647)
            return (0);
    }
    if (nbr > 0){
        if (neg % 2 == 1)
            nbr *= (-1);
        return (nbr);
    }
    return (0);
}

int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_str_find(char *c, char *arr)
{
    int res = 0;

    for (int i = 0; arr[i]; ++i)
        for (int i = 0; c[i]; ++i)
            res += (c[i] == arr[i]) ? 1 : 0;
    return res;
}

int my_char_nbfind(char c, char *arr)
{
    int res = 0;

    for (int i = 0; arr[i]; ++i)
        res += (c == arr[i]) ? 1 : 0;
    return (res);
}

int my_str_isnum(char *str)
{
    for (int i = 0; str[i]; ++i)
        if (!my_char_nbfind(str[i], "0123456789"))
            return 0;
    return 1;
}