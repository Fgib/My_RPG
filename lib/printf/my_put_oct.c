/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_put_oct
*/

int pnbr(int nb);

void poct(int dec_nbr)
{
    int oct_nbr = 0;

    for (int i = 1; dec_nbr != 0; i *=10) {
        oct_nbr += (dec_nbr % 8) * i;
        dec_nbr /= 8;
    }
    pnbr(oct_nbr);
}