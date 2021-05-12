/*
** EPITECH PROJECT, 2021
** B-CPE-200-LYN-2-1-matchstick-florian.gibault
** File description:
** my_int_str
*/

#include <stdlib.h>

int my_strlen(char *str);
int score_debugger(int nbr);

char *get_str(int val)
{
    int len = score_debugger(val);
    char *result = malloc(sizeof(char) * (len + 1));

    result[len] = '\0';
    while (len--) {
        result[len] = val %10 + 48;
        val = val / 10;
    }
    return (result);
}

int score_debugger(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}