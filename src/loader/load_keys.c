/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_keys
*/

#include "my_rpg.h"


void load_key_mapping(keymap_t *keys)
{
    keys->left = 16;
    keys->right = 3;
    keys->backward = 18;
    keys->forward = 25;
    keys->inventory = 4;
    keys->space = 58;
    keys->interact = 5;
    keys->num1 = 27;
    keys->num2 = 28;
    keys->num3 = 29;
    keys->num4 = 30;
    keys->num5 = 31;
    keys->num6 = 32;
    keys->num7 = 33;
    keys->num8 = 34;
    keys->num9 = 35;
}

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