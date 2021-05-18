/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_editor3
*/

#include "my_rpg.h"

void load_editor_background(gen_t *prm)
{
    sfTexture *blank_tile = sfTexture_createFromFile
    ("assets/blank_tile.png", NULL);
    sfTexture_setRepeated(blank_tile, sfTrue);
    prm->editor.view_rect = sfSprite_create();
    sfSprite_setTexture(prm->editor.view_rect, blank_tile, sfFalse);
    sfSprite_setTextureRect(prm->editor.view_rect,
    get_intrect(0, 0, 256 * prm->editor.scenario->mapsize.x,
    256 * prm->editor.scenario->mapsize.y));
}

void load_editor_exit_menu(gen_t *prm)
{
    prm->editor.trans = initialize_button((vec_t){716, 360},
    (vec_t){0, 0}, (sfVector2f){3.2, 2.13}, "assets/tri_button.png");
    prm->editor.retour = initialize_button((vec_t){726, 380},
    (vec_t){468, 94}, (sfVector2f){3, 0.6}, "assets/tri_button.png");
    prm->editor.exit_brut = initialize_button((vec_t){726, 480},
    (vec_t){468, 94}, (sfVector2f){3, 0.6}, "assets/tri_button.png");
    prm->editor.exit_save = initialize_button((vec_t){726, 580},
    (vec_t){468, 94}, (sfVector2f){3, 0.6}, "assets/tri_button.png");
    sfSprite_setTextureRect(prm->editor.trans->sprite,
    get_intrect(0, 0, 156, 156));
    load_text_button(prm->editor.exit_brut, (vec3_t){5, 5, 40},
    "Exit without saving");
    load_text_button(prm->editor.exit_save, (vec3_t){5, 5, 40},
    "Exit and save");
    load_text_button(prm->editor.retour, (vec3_t){5, 5, 40}, "Back");
}

void load_editor_gui_tools(gen_t *prm)
{
    prm->editor.hide_zones = initialize_trigger
    ((sfVector2f){1150, 35}, "Hide data");
    prm->editor.zones_selector = initialize_slider
    (1500, 13, 50, "Enemies zone selection");
    prm->editor.texture_reset = initialize_button
    ((vec_t){80, 1000}, (vec_t){140, 39}, get_vector(0.9, 0.25),
    "assets/tri_button.png");
    load_text_button(prm->editor.texture_reset, (vec3_t){30, 5, 25}, "RESET");
    prm->editor.enemies = initialize_button((vec_t){400, 10},
    (vec_t){75, 75}, get_vector(1.4, 1.4), "assets/cell.png");
    prm->editor.hitbox = initialize_button((vec_t){500, 10},
    (vec_t){75, 75}, get_vector(1.4, 1.4), "assets/cell.png");
    prm->editor.spawnpoint = initialize_button((vec_t){600, 10},
    (vec_t){75, 75}, get_vector(1.4, 1.4), "assets/cell.png");
    prm->editor.endpoint = initialize_button((vec_t){800, 10},
    (vec_t){75, 75}, get_vector(1.4, 1.4), "assets/cell.png");
    load_text_button(prm->editor.enemies, (vec3_t){15, 30, 15}, "MOBS");
    load_text_button(prm->editor.hitbox, (vec3_t){5, 30, 15}, "HITBOX");
    load_text_button(prm->editor.spawnpoint, (vec3_t){5, 30, 15}, "SPAWN");
    load_text_button(prm->editor.endpoint, (vec3_t){15, 30, 15}, "END");
}

void load_editor_gui(gen_t *prm)
{
    prm->editor.bar = get_sprite("assets/Wenra/MainPanel03.png");
    prm->editor.select = get_sprite("assets/Wenra/MainPanel02.png");
    sfSprite_setScale(prm->editor.bar, get_vector(6.35, 0.65));
    sfSprite_setPosition(prm->editor.select, get_vector(0, 93));
    sfSprite_setScale(prm->editor.select, get_vector(1, 2.43));
}

void load_editor_scenario_stuff(gen_t *prm)
{
    prm->editor.scenario = malloc(sizeof(scenario_t));
    prm->editor.scenario->path = prm->path;
    prm->editor.scenario->row_data =
    my_str_splitter(my_file_loader(prm->editor.scenario->path), '\n');
    prm->editor.scenario->name = "Joli Nom";
    get_dictionnary(prm->editor.scenario);
    get_map(prm, prm->editor.scenario);
    get_positions(prm->editor.scenario);
    draw_start(&prm->editor, prm->editor.scenario->start);
    prm->editor.last_mouse_pos = (vec_t){0, 0};
}