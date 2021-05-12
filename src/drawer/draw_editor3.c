/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** draw_editor3
*/

#include "my_rpg.h"

void draw_editor_exiting(gen_t *prm)
{
    DRAW_S(prm->editor.trans->sprite);
    DRAW_S(prm->editor.retour->sprite);
    DRAW_T(prm->editor.retour->text);
    DRAW_S(prm->editor.exit_brut->sprite);
    DRAW_T(prm->editor.exit_brut->text);
    DRAW_S(prm->editor.exit_save->sprite);
    DRAW_T(prm->editor.exit_save->text);
}

void draw_editor_print_deco(gen_t *prm)
{
    for (int i = 0; i < 12; i++) {
        DRAW_S(prm->editor.deco_type[i]->sprite);
        DRAW_S(prm->editor.deco_type[i]->icon);
    }
    DRAW_S(prm->editor.texture_reset->sprite);
    DRAW_T(prm->editor.texture_reset->text);
}

void draw_editor(gen_t *prm)
{
    sfRenderWindow_setView(prm->window, prm->editor.edit_win);
    DRAW_S(prm->editor.view_rect);
    view_movement(prm);
    draw_editor_print_map(prm);
    draw_editor_print_cursor(prm);
    sfView_setCenter(prm->editor.edit_win, prm->editor.cam_pos);
    sfRenderWindow_setView(prm->window, prm->editor.interface);
    draw_editor_print_gui(prm);
    if (prm->editor.edit_step == ENEMIES_INFO ||
        prm->editor.edit_step == ENEMIES_STAT)
        draw_editor_enemies_tabs(prm);
    if (prm->editor.edit_step == ENEMIES_STAT)
        draw_editor_enemies_stats(prm);
    if (prm->editor.pmod == WALL || prm->editor.pmod == FLOOR)
        draw_editor_wall_floor(prm);
    if (prm->editor.edit_step == EXITING)
        draw_editor_exiting(prm);
    if (prm->editor.pmod == DECO)
        draw_editor_print_deco(prm);
}

void draw_editor_wall_floor(gen_t *prm)
{
    DRAW_S(prm->editor.block_tileset);
    if (prm->editor.texture_selected != -1) {
        DRAW_S(prm->editor.cursor);
        sfSprite_setPosition(prm->editor.cursor,
        get_vector(5 + (prm->editor.texture_selected % 6 * 48),
        180 + (prm->editor.texture_selected / 6 * 48)));
    }
    if (prm->editor.texture_locked != -1) {
        DRAW_S(prm->editor.cursor_locked);
        sfSprite_setPosition(prm->editor.cursor_locked,
        get_vector(5 + (prm->editor.texture_locked % 6 * 48),
        180 + (prm->editor.texture_locked / 6 * 48)));
        DRAW_S(prm->editor.texture_reset->sprite);
        DRAW_T(prm->editor.texture_reset->text);
    }
}