/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** 
*/

#include <stdlib.h>

int pnbr(int nb);
void pchar(char c);

void my_awesome_printer(int nbr)
{
    int char1;
    int char2;

    char1 = nbr % 10;
    char2 = nbr / 10;
    pnbr(char2);
    pnbr(char1);
}

int pnbr(int nb)
{
    if (nb == -2147483648) {
        pchar('-');
        pchar('2');
        pnbr(147483648);
        return (0);
    }
    if (nb < 0) {
        nb = nb * (-1);
        pchar('-');
    }
    if (nb < 10) {
        pchar(nb + 48);
    }
    else
    {
        my_awesome_printer(nb);
    }
    return (0);
}

int sdebug(int nbr)
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

char *gstr(int val)
{
    int len = sdebug(val);
    char *result = malloc(sizeof(char) * (len + 1));

    result[len] = '\0';
    while (len--) {
        result[len] = val %10 + 48;
        val = val / 10;
    }
    return (result);
}