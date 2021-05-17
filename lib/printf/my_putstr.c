/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** 
*/

void pchar(char c);

int pstr(char *str)
{
    int cpt = 0;

    while (str[cpt] != '\0') {
        pchar(str[cpt]);
        cpt++;
    }
    return (0);
}