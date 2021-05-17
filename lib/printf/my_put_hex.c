/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_put_hex
*/

void my_printf(char *str, ...);
void pchar(char c);

void phexm(int dec_nbr)
{
    int retain;
    int j = 0;
    char hex_nbr[100];
    int quot = dec_nbr;

    for (; quot != 0;) {
        retain = quot % 16;
        if (retain < 10)
            hex_nbr[j++] = 48 + retain;
        else
            hex_nbr[j++] = 55 + retain;
        quot = quot / 16;
    }
    for (int i = j; i >= 0; i--)
        pchar(hex_nbr[i]);
}

void phexa(int dec_nbr)
{
    int retain;
    int j = 0;
    char hex_nbr[100];
    int quot = dec_nbr;

    for (; quot != 0;) {
        retain = quot % 16;
        if (retain < 10)
            hex_nbr[j++] = 48 + retain;
        else
            hex_nbr[j++] = 87 + retain;
        quot = quot / 16;
    }
    for (int i = j; i >= 0; i--)
        pchar(hex_nbr[i]);
}