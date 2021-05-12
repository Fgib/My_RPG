/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_keys
*/

#include "my_rpg.h"

keys_t load_keys(void)
{
    keys_t keys;

    keys.mv_down = 0;
    keys.mv_up = 0;
    keys.mv_right = 0;
    keys.mv_left = 0;
    keys.mouse = 0;
    keys.space = 0;
    keys.tab = 0;
    return keys;
}