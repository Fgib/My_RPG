/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** drawe_dispatch
*/

#include "my_rpg.h"

void window_update(gen_t *prm)
{
    if (prm->game_step == HOME)
        draw_home(prm);
    if (prm->game_step == SETTINGS)
        draw_settings(prm);
    if (prm->game_step ==CUSTOM)
        draw_custom(prm);
    if (prm->game_step == EDITOR_ENGINE)
        draw_editor(prm);
    if (prm->game_step == GAME)
        draw_game(prm);
    if (prm->game_step == SAVE_SELECTOR)
        draw_save_selector(prm);
    if (prm->game_step == PAUSE || prm->game_step == PAUSE_SAVE)
        draw_pause(prm);
}