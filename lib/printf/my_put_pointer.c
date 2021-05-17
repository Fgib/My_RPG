/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_put_pointer
*/

void phexa(int dec_nbr);
int pstr(char const *str);

void pptr(int value)
{
    pstr("0x");
    phexa(value);
}