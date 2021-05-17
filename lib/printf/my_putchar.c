/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** 
*/

#include <unistd.h>

void pchar(char c)
{
    write(1, &c, 1);
}
