/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_editor
*/

#include "my_rpg.h"

void draw_editor_print_map_insider(gen_t *prm, int i, int j)
{
    for (int k = 0; k < prm->editor.scenario->mapsize.y; ++k)
        if (i != 3 || !prm->editor.hide_zones->state)
            DRAW_S(prm->editor.scenario->spmap[k][j][i]);
}

void draw_editor_print_map(gen_t *prm)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < prm->editor.scenario->mapsize.x; j++) {
            draw_editor_print_map_insider(prm, i, j);
        }
    }
}

void draw_editor_print_cursor(gen_t *prm)
{
    if (prm->editor.last_mouse_pos.x > 300 &&
    prm->editor.last_mouse_pos.y > 96 &&
    prm->editor.edit_step == DEFAULT) {
        DRAW_S(prm->editor.edit_cursor);
        sfSprite_setPosition(prm->editor.edit_cursor,
        (sfVector2f){prm->editor.mouse_tile_pos.x * 256,
            prm->editor.mouse_tile_pos.y * 256});
    }
}