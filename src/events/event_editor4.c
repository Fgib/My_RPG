/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_editor4
*/

#include "my_rpg.h"

void editor_events_mouse_visibility(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseMoved)
        prm->editor.last_mouse_pos = (vec_t){prm->event.mouseMove.x,
            prm->event.mouseMove.y};
    if (prm->editor.last_mouse_pos.x > 300 &&
    prm->editor.last_mouse_pos.y > 96) {
        sfRenderWindow_setMouseCursorVisible(prm->window, sfFalse);
        float tile_size = (float)(256) * powf(1.05, prm->editor.zoom);
        prm->editor.mouse_tile_pos.x = (prm->editor.last_mouse_pos.x - 960 +
        prm->editor.cam_pos.x * powf(1.05, prm->editor.zoom)) / tile_size;
        prm->editor.mouse_tile_pos.y = (prm->editor.last_mouse_pos.y - 540 +
        prm->editor.cam_pos.y * powf(1.05, prm->editor.zoom)) / tile_size;
    } else
        sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
}

void editor_events_enemies_menu_add_enemy(gen_t *prm)
{
    if (click_rel(prm->event, prm->editor.pop_info)) {
        prm->editor.edit_step = DEFAULT;
    } else if (click_rel(prm->event,
    prm->editor.enemies_tab[prm->editor.scenario->dic_count])) {
        prm->editor.enemies_tab[prm->editor.scenario->dic_count] =
        initialize_button((vec_t){375 +
            (prm->editor.scenario->dic_count % 5 * 75), 260 +
            (prm->editor.scenario->dic_count/ 5 * 75)}, (vec_t){60, 60},
        get_vector(0.5, 0.5), "assets/Wenra/Button07.png");
        enemy_t_push(&prm->editor.scenario->dictionnary,
        &prm->editor.scenario->dic_count,
        ((enemy_t){(sfVector2f){0, 0}, 0, 0, 0, 0, 0, 0, 0, 0, "", NULL, 0}));
        prm->editor.enemies_tab[prm->editor.scenario->dic_count] =
        initialize_button((vec_t){375 +
            (prm->editor.scenario->dic_count % 5 * 75), 260 +
            (prm->editor.scenario->dic_count/ 5 * 75)}, (vec_t){60, 60},
        get_vector(0.5, 0.5), "assets/Wenra/Button08.png");
        return;
    }
}

void editor_events_enemies_menu_get_stats(gen_t *prm)
{
    for (int i = 0; i < prm->editor.scenario->dic_count; i++) {
        if (click_rel(prm->event, prm->editor.enemies_tab[i]) &&
        !prm->keys.space) {
            prm->editor.enemy_selected = i;
            prm->editor.edit_step = ENEMIES_STAT;
        } else if (click_rel(prm->event, prm->editor.enemies_tab[i]) &&
        prm->keys.space) {
            prm->editor.edit_step = ENEMIES_INFO;
            delete_enemy_btn(&prm->editor, i);
        }
    }
}

void editor_events_enemies_menu(gen_t *prm)
{
    if (prm->editor.edit_step == ENEMIES_INFO ||
    prm->editor.edit_step == ENEMIES_STAT) {
        sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
        editor_events_enemies_menu_add_enemy(prm);
        editor_events_enemies_menu_get_stats(prm);
        if (prm->editor.edit_step == ENEMIES_STAT) {
            editor_enemy_stat_event(prm);
        }
    }
}

void editor_events_pen_selector(gen_t *prm)
{
    for (int i = 0; i < 5; i++) {
        if (triforce(prm->event, prm->editor.pen_type[i]))
            prm->editor.pmod = i;
    }
}