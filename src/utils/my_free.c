/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_free
*/

#include "my_rpg.h"

void my_free(int nb, ...)
{
    va_list ap;
    void *func;

    va_start(ap, nb);
    for (int i = 0; i < nb; ++i) {
        func = va_arg(ap, void *);
        free(func);
    }
    va_end(ap);
}