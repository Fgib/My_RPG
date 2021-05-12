/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_editor4
*/

#include "my_rpg.h"

void editor_enemy_setup_loading4(gen_t *prm)
{
    sfIntRect zone = get_intrect(0, 0, 53, 53);
    sfSprite_setTextureRect(prm->editor.hp_plus->sprite, zone);
    sfSprite_setTextureRect(prm->editor.hp_moins->sprite, zone);
    sfSprite_setTextureRect(prm->editor.armor_plus->sprite, zone);
    sfSprite_setTextureRect(prm->editor.armor_moins->sprite, zone);
    sfSprite_setTextureRect(prm->editor.range_plus->sprite, zone);
    sfSprite_setTextureRect(prm->editor.range_moins->sprite, zone);
    sfSprite_setTextureRect(prm->editor.speed_plus->sprite, zone);
    sfSprite_setTextureRect(prm->editor.speed_moins->sprite, zone);
    sfSprite_setTextureRect(prm->editor.nb_plus->sprite, zone);
    sfSprite_setTextureRect(prm->editor.nb_moins->sprite, zone);
}

void editor_enemy_setup_loading(gen_t *prm)
{
    prm->editor.hp_val = load_text_str("", 50, (vec_t){1250, 350});
    prm->editor.armor_val = load_text_str("", 50, (vec_t){1250, 450});
    prm->editor.range_val = load_text_str("", 50, (vec_t){1250, 550});
    prm->editor.speed_val = load_text_str("", 50, (vec_t){1250, 650});
    prm->editor.nb_val = load_text_str("", 50, (vec_t){1250, 750});
    editor_enemy_setup_loading2(prm);
    editor_enemy_setup_loading3(prm);
    editor_enemy_setup_loading4(prm);
}

void load_editor_cursor_stuff(gen_t *prm)
{
    prm->editor.block_tileset = get_sprite("assets/full_tileset.png");
    sfSprite_setPosition(prm->editor.block_tileset, get_vector(5, 180));
    sfSprite_setScale(prm->editor.block_tileset, get_vector(0.19, 0.19));
    prm->editor.cursor = get_sprite("assets/cursor.png");
    sfSprite_setTextureRect(prm->editor.cursor, get_intrect(0, 0, 48, 48));
    prm->editor.cursor_locked = get_sprite("assets/cursor.png");
    sfSprite_setTextureRect(prm->editor.cursor_locked,
    get_intrect(0, 0, 48, 48));
    sfSprite_setColor(prm->editor.cursor_locked, (sfColor){255, 0, 0, 255});
    prm->editor.texture_locked = -1;
    prm->editor.edit_cursor = get_sprite("assets/cursor.png");
    sfSprite_setScale(prm->editor.edit_cursor, get_vector(5.32, 5.32));
}

void load_editor_initialisation(gen_t *prm)
{
    prm->editor.zoom = 0;
    prm->editor.zone_id = 0;
    prm->editor.pmod = SELECT;
    prm->editor.pencil_type = 0;
    prm->editor.edit_step = DEFAULT;
    prm->editor.cam_pos = get_vector(0, 0);
    prm->editor.edit_win = sfView_createFromRect
    ((sfFloatRect){0, 0, 1920, 1080});
    prm->editor.interface = sfView_createFromRect
    ((sfFloatRect){0, 0, 1920, 1080});
}