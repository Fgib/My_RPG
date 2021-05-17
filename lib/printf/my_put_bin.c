/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_put_bin
*/

int pnbr(int nb);

void pbin(int nbr)
{
    int bin_array[32];
    int i;

    for (i = 0; nbr > 0; i++) {
        bin_array[i] = nbr % 2;
        nbr = nbr / 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        pnbr(bin_array[j]);
    }
}