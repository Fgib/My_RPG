/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** utils
*/

#include "my_rpg.h"

int get_xp_for_level(int level)
{
    if (level < 2)
        return 0;
    return 250 * log(level / 2);
}