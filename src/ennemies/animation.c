/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** animation
*/

#include "my_rpg.h"

void enemies_animation(enemy_t *mob, int angle)
{
    int dir = angle / 90;

    mob->skin_id += mob->skin_id < 29 ? 1 : -29;
    (void)dir;
    sfSprite_setTextureRect(mob->sprite,
    get_intrect(48 * dir, 48 * (mob->skin_id / 10), 48, 48));
}