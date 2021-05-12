/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** triforce
*/

#include "my_rpg.h"

int click_rel(sfEvent event, struct button *target)
{
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;

    if (event.type != sfEvtMouseButtonReleased)
        return 0;
    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return 1;
    }
    return 0;
}

int click_pre(sfEvent event, struct button *target)
{
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;

    if (event.type != sfEvtMouseButtonPressed)
        return 0;
    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return 1;
    }
    return 0;
}

int click_is_up(sfEvent event, struct button *target)
{
    int hit_x = event.mouseMove.x;
    int hit_y = event.mouseMove.y;

    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return 1;
    }
    return 0;
}

int triforce(sfEvent event, struct button *target)
{
    if (click_pre(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 2 * 156, 156, 156));
    } else if (click_is_up(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 156, 156, 156));
    } else {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 0, 156, 156));
    }
    if (click_rel(event, target)) {
        return 1;
    }
    return 0;
}

int duoforce(sfEvent event, struct button *target, int size)
{
    if (click_is_up(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, size, size, size));
    } else
        sfSprite_setTextureRect(target->sprite, get_intrect(0, 0, size, size));
    if (click_rel(event, target))
        return 1;
    return 0;
}