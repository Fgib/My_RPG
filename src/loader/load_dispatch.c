/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** dispatch
*/

#include "my_rpg.h"

gen_t *get_struct_settings(void)
{
    gen_t *prm = malloc(sizeof(gen_t));
    prm->animation_clock = sfClock_create();
    prm->window = window_creator();
    prm->pause = get_pause_s();
    prm->game_step = HOME;
    prm->saves.save = "players.save";
    prm->keys = load_keys();
    prm->loading = get_sprite("assets/loading_screen.png");
    prm->tilesets = malloc(sizeof(sfTexture *) * 4);
    prm->tilesets[0] = T_FROMFILE("assets/full_tileset.png");
    prm->tilesets[1] = T_FROMFILE("assets/deco_tileset.png");
    prm->tilesets[2] = T_FROMFILE("assets/blank_tile.png");
    prm->tilesets[3] = T_FROMFILE("assets/zones.png");
    get_items(prm);
    load_home_struct(prm);
    load_custom_struct(prm);
    get_saves(prm);
    write(1, "Everything loaded successfully\n\n", 32);
    return prm;
}