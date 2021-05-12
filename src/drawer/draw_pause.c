/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** draw_pause
*/

#include "my_rpg.h"

void draw_pause_menu(gen_t *prm)
{
    DRAW_S(prm->pause->transp->sprite);
    DRAW_S(prm->pause->resume_b->sprite);
    DRAW_S(prm->pause->restart_b->sprite);
    DRAW_S(prm->pause->settings_b->sprite);
    DRAW_S(prm->pause->menu_b->sprite);
    DRAW_S(prm->pause->exit_b->sprite);
    DRAW_T(prm->pause->transp->text);
    DRAW_T(prm->pause->resume_b->text);
    DRAW_T(prm->pause->restart_b->text);
    DRAW_T(prm->pause->settings_b->text);
    DRAW_T(prm->pause->menu_b->text);
    DRAW_T(prm->pause->exit_b->text);
}

void draw_pause_save(gen_t *prm)
{
    DRAW_S(prm->pause->transp2->sprite);
    DRAW_S(prm->pause->save_n->sprite);
    DRAW_S(prm->pause->save_y->sprite);
    DRAW_T(prm->pause->transp2->text);
    DRAW_T(prm->pause->save_n->text);
    DRAW_T(prm->pause->save_y->text);
}

void draw_pause(gen_t *prm)
{
    DRAW_S(prm->pause->calc);
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    if (prm->game_step == PAUSE) {
        draw_pause_menu(prm);
    } else {
        draw_pause_save(prm);
    }
}