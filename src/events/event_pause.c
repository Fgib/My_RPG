/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_pause
*/

#include "my_rpg.h"

void pause_menu_event1(gen_t *prm)
{
    if (triforce(prm->event, prm->pause->resume_b)) {
        prm->game_step = GAME;
    }
    if (triforce(prm->event, prm->pause->settings_b))
        prm->game_step = G_SETTINGS;
    if (triforce(prm->event, prm->pause->menu_b)) {
        prm->game_step = HOME;
    }
    if (triforce(prm->event, prm->pause->exit_b)) {
        prm->game_step = OUT;
    }
}

void pause_menu_event2(gen_t *prm)
{
    if (triforce(prm->event, prm->pause->save_y)) {
        save_sessions(&prm->saves);
    }
    if (triforce(prm->event, prm->pause->save_n))
        prm->game_step = HOME;
}

void pause_menu_event(gen_t *prm)
{
    if (prm->game_step == PAUSE) {
        pause_menu_event1(prm);
    }
    if (prm->game_step == PAUSE_SAVE) {
        pause_menu_event2(prm);
    }
}