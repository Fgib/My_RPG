/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** key_strokes
*/

#include "my_rpg.h"

void key_pressed(gen_t *prm)
{
    if (prm->event.type == sfEvtKeyPressed) {
        if (prm->event.key.code == KEY(forward))
            prm->keys.mv_up = 1;
        if (prm->event.key.code == KEY(left))
            prm->keys.mv_left = 1;
        if (prm->event.key.code == KEY(backward))
            prm->keys.mv_down = 1;
        if (prm->event.key.code == KEY(right))
            prm->keys.mv_right = 1;
        if (prm->event.key.code == KEY(space))
            prm->keys.space = 1;
    }
}

void key_released(gen_t *prm)
{
    if (prm->event.type == sfEvtKeyReleased) {
        if (prm->event.key.code == KEY(forward))
            prm->keys.mv_up = 0;
        if (prm->event.key.code == KEY(left))
            prm->keys.mv_left = 0;
        if (prm->event.key.code == KEY(backward))
            prm->keys.mv_down = 0;
        if (prm->event.key.code == KEY(right))
            prm->keys.mv_right = 0;
        if (prm->event.key.code == KEY(space))
            prm->keys.space = 0;
    }
}

void directional_pressed(gen_t * prm)
{
    if (prm->event.type == sfEvtKeyPressed) {
        if (prm->event.key.code == sfKeyUp)
            prm->keys.arr_up = 1;
        if (prm->event.key.code == sfKeyRight)
            prm->keys.arr_right = 1;
        if (prm->event.key.code == sfKeyDown)
            prm->keys.arr_down = 1;
        if (prm->event.key.code == sfKeyLeft)
            prm->keys.arr_left = 1;
    }
}

void directional_released(gen_t * prm)
{
    if (prm->event.type == sfEvtKeyReleased) {
        if (prm->event.key.code == sfKeyUp)
            prm->keys.arr_up = 0;
        if (prm->event.key.code == sfKeyRight)
            prm->keys.arr_right = 0;
        if (prm->event.key.code == sfKeyDown)
            prm->keys.arr_down = 0;
        if (prm->event.key.code == sfKeyLeft)
            prm->keys.arr_left = 0;
    }
}

void keys_stuff(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseButtonPressed)
        prm->keys.mouse = 1;
    if (prm->event.type == sfEvtMouseButtonReleased)
        prm->keys.mouse = 0;
    key_pressed(prm);
    key_released(prm);
    directional_pressed(prm);
    directional_released(prm);
}