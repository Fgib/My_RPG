/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_save_selector
*/

#include "my_rpg.h"

void events_save_selector_bis(gen_t *prm)
{
    if (prm->save_sel.selected != 1) {
        if (triforce(prm->event, prm->save_sel.save_two)) {
            sfSprite_setTextureRect(prm->save_sel.save_two->sprite,
            get_intrect(0, 312, 156, 156));
            prm->save_sel.selected = 1;
        }
    }
    if (prm->save_sel.selected != 2) {
        if (triforce(prm->event, prm->save_sel.save_tre)) {
            sfSprite_setTextureRect(prm->save_sel.save_tre->sprite,
            get_intrect(0, 312, 156, 156));
            prm->save_sel.selected = 2;
        }
    }
}

void events_save_selector(gen_t *prm)
{
    if (triforce(prm->event, prm->save_sel.choose) &&
    prm->save_sel.selected != 1) {
        DRAW_S(prm->loading);
        sfRenderWindow_display(prm->window);
        load_game_struct(prm);
        prm->game_step = GAME;
    }
    if (prm->save_sel.selected != 0) {
        if (triforce(prm->event, prm->save_sel.save_one)) {
            sfSprite_setTextureRect(prm->save_sel.save_one->sprite,
            get_intrect(0, 312, 156, 156));
            prm->save_sel.selected = 0;
        }
    }
    events_save_selector_bis(prm);
}