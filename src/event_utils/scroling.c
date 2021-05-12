/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** scroling
*/

#include "my_rpg.h"

void editor_zoom(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseWheelScrolled) {
        if (prm->event.mouseWheelScroll.delta > 0 && prm->editor.zoom < 0) {
            sfView_zoom(prm->editor.edit_win, 0.95);
            prm->editor.zoom += 1;
        }
        if (prm->event.mouseWheelScroll.delta < 0 && prm->editor.zoom > -40) {
            sfView_zoom(prm->editor.edit_win, 1.05);
            prm->editor.zoom -= 1;
        }
    }
}

void game_engine_zoom(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseWheelScrolled) {
        if (prm->event.mouseWheelScroll.delta > 0 && prm->game.zoom < 0) {
            sfView_zoom(prm->game.rendering, 0.95);
            prm->game.zoom += 1;
        }
        if (prm->event.mouseWheelScroll.delta < 0 && prm->game.zoom > -20) {
            sfView_zoom(prm->game.rendering, 1.05);
            prm->game.zoom -= 1;
        }
    }
}