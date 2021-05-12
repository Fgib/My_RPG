/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_custom
*/

#include "my_rpg.h"

void custom_events(gen_t *prm)
{
    if (prm->keys.mouse) {
        slider_event(prm->custom.red, prm->event);
        slider_event(prm->custom.green, prm->event);
        slider_event(prm->custom.blue, prm->event);
        sfSprite_setColor(prm->custom.expl, prm->custom.color);
    }
    prm->custom.color = (sfColor){prm->custom.red->value * 2.55,
        prm->custom.green->value * 2.55, prm->custom.blue->value * 2.55, 255};
    if (triforce(prm->event, prm->custom.save)) {
        prm->game_step = HOME;
    }

}