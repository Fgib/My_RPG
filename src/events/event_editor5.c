/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_editor5
*/

#include "my_rpg.h"

void editor_events_drawing(gen_t *prm)
{
    if (prm->editor.edit_step == DEFAULT && prm->keys.mouse &&
    prm->editor.last_mouse_pos.x > 300 && prm->editor.last_mouse_pos.y > 96) {
        draw(&prm->editor, (vec_t){prm->editor.mouse_tile_pos.x,
            prm->editor.mouse_tile_pos.y});
    }
}

void editor_events_enemies_zone_selector(gen_t *prm)
{
    if (prm->keys.mouse)
        slider_event(prm->editor.zones_selector, prm->event);
    trigger_event(prm->editor.hide_zones, prm->event);
}

void editor_events_texture_selection(gen_t *prm)
{
    if (prm->editor.pmod == FLOOR || prm->editor.pmod == WALL) {
        sfFloatRect data = sfSprite_getGlobalBounds(prm->editor.block_tileset);
        if (sfFloatRect_contains(&data, prm->event.mouseMove.x,
        prm->event.mouseMove.y)) {
            prm->editor.texture_selected = ((prm->event.mouseMove.x - 5) / 48) +
            ((prm->event.mouseMove.y - 180) / 48) * 6;
        } else if (prm->keys.mouse && sfFloatRect_contains(&data,
        prm->event.mouseButton.x, prm->event.mouseButton.y)) {
            prm->editor.texture_locked = prm->editor.texture_selected;
        } else
            prm->editor.texture_selected = -1;
        if (prm->editor.texture_locked != -1 &&
            triforce(prm->event, prm->editor.texture_reset))
            prm->editor.texture_locked = -1;
    }
}

void editor_events_deco_brush(gen_t *prm)
{
    if (prm->editor.pmod == DECO) {
        editor_deco_button_event(prm);
        if (triforce(prm->event, prm->editor.texture_reset))
            prm->editor.deco_selected = -1;
    } else
        prm->editor.deco_selected = -1;
}

void editor_events(gen_t *prm)
{
    editor_events_mouse_visibility(prm);
    save_menu_event(prm);
    editor_zoom(prm);
    editor_events_enemies_menu(prm);
    editor_events_pen_selector(prm);
    editor_events_drawing(prm);
    editor_events_taskbar(prm);
    editor_events_enemies_zone_selector(prm);
    editor_events_texture_selection(prm);
    editor_events_deco_brush(prm);
}