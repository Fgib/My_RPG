/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get
*/

#include "my_rpg.h"

int get_int_data(char *balise, char **json)
{
    char *buff = get_inline_content(json, balise);

    if (buff == NULL || !my_strcmp(buff, ""))
        return -1;
    return my_getnbr(buff);
}