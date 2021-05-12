/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event_home
*/

#include "my_rpg.h"

void home_event_bis(gen_t *prm)
{
    if (triforce(prm->event, prm->home.sett_b)) {
        prm->setting = load_settings_menu();
        prm->game_step = SETTINGS;
    }
    if (triforce(prm->event, prm->home.abou_b)) {}
    if (triforce(prm->event, prm->home.exit_b))
        prm->game_step = OUT;
}

void home_event(gen_t *prm)
{
    if (triforce(prm->event, prm->home.play_b)) {
        load_save_selector(prm);
        prm->game_step = SAVE_SELECTOR;
    }
    if (triforce(prm->event, prm->home.edit_b)) {
        DRAW_S(prm->loading);
        sfRenderWindow_display(prm->window);
        load_editor_struct(prm);
        prm->game_step = EDITOR_ENGINE;
    }
    if (triforce(prm->event, prm->home.cstm_b)) {
        DRAW_S(prm->loading);
        sfRenderWindow_display(prm->window);
        prm->game_step = CUSTOM;
    }
    home_event_bis(prm);
}