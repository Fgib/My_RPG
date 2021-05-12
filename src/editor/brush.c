/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** wall_brush
*/

#include "my_rpg.h"



void draw_wall(editor_t *edit, vec_t pos)
{
    int x = edit->texture_locked % 6 * 256;
    int y = edit->texture_locked / 6 * 256;

    if (edit->texture_locked == -1) {
        edit->scenario->vmap[pos.y][pos.x][3] = 0;
        edit->scenario->vmap[pos.y][pos.x][0] = 0;
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][0],
        get_intrect(0, 0, 0, 0));
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][3],
        get_intrect(0, 0, 0, 0));
    } else {
        edit->scenario->vmap[pos.y][pos.x][3] = -1;
        edit->scenario->vmap[pos.y][pos.x][0] = edit->texture_locked;
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][0],
        get_intrect(y, x, 256, 256));
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][3],
        get_intrect(0, 0, 256, 256));
    }
}

void draw_texture(editor_t *edit, vec_t pos, int is_deco)
{
    int x = edit->texture_locked / 6 * 256;
    int y = edit->texture_locked % 6 * 256;
    sfIntRect deco;

    if (is_deco) {
        deco = edit->liste_deco[edit->deco_selected];
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][1],
        (edit->deco_selected == -1) ? get_intrect(0, 0, 0, 0) : deco);
        edit->scenario->vmap[pos.y][pos.x][1] = (edit->deco_selected != -1)
        ? edit->deco_selected : 0;
    } else {
        if (edit->texture_locked == -1)
            sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][0],
            get_intrect(0, 0, 0, 0));
        else
            sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][0],
            get_intrect(x, y, 256, 256));
        edit->scenario->vmap[pos.y][pos.x][0] = (edit->texture_locked != -1)
        ? edit->texture_locked : 0;
    }
}

void draw_zone(editor_t *edit, vec_t pos, int id)
{
    if (edit->scenario->vmap[pos.y][pos.x][3] != id && id != 0) {
        edit->scenario->vmap[pos.y][pos.x][3] = id;
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][3],
        get_intrect(0, (id == -1) ? 0 : id * 256, 256, 256));
    } else {
        edit->scenario->vmap[pos.y][pos.x][3] = 0;
        sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][3],
        get_intrect(0, 0, 0, 0));
    }
}

void draw_start(editor_t *edit, vec_t pos)
{
    vec_t temp = edit->scenario->start;

    sfSprite_setTextureRect(edit->scenario->spmap[temp.y][temp.x][3],
    get_intrect(0, 0, 0, 0));
    SVEC(edit->scenario->start, pos);
    sfSprite_setTextureRect(edit->scenario->spmap[pos.y][pos.x][3],
    get_intrect(0, 17 * 256, 256, 256));
}

void draw(editor_t *edit, vec_t pos)
{
    if (edit->scenario->mapsize.x < pos.x || edit->scenario->mapsize.y < pos.y)
        return;
    if (pos.x < 0 || pos.y < 0)
        return;

    switch (edit->pmod) {
    case FLOOR: draw_texture(edit, pos, 0);
        break;
    case WALL: draw_wall(edit, pos);
        break;
    case DECO: draw_texture(edit, pos, 1);
        break;
    case ZONES: draw_zone(edit, pos, edit->zones_selector->value * 0.14 + 1);
        break;
    case HITBOX: draw_zone(edit, pos, -1);
        break;
    case SPAWN: draw_start(edit, pos);
        break;
    default: break;
    }
}