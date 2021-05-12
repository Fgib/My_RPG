/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** strokes_count
*/

#include "my_rpg.h"

int strokes_count(keys_t key)
{
    int result = key.mv_down + key.mv_left + key.mv_right + key.mv_up;
    if (result > 1)
        return 2;
    else if (result == 1)
        return 1;
    else
        return 0;
}