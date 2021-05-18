/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_editor2
*/

#include "my_rpg.h"

void reload_editor_deco_button_event(gen_t *prm)
{
    for (int i = 0; i < 12; i++)
        sfSprite_setTextureRect(prm->editor.deco_type[i]->sprite,
        get_intrect(0, 0, 53, 53));
}

void editor_deco_button_event(gen_t *prm)
{
    for (int i = 0; i < 12; i++) {
        if (click_rel(prm->event, prm->editor.deco_type[i])) {
            reload_editor_deco_button_event(prm);
            sfSprite_setTextureRect(prm->editor.deco_type[i]->sprite,
            get_intrect(0, 53, 53, 53));
            prm->editor.deco_selected = i;
        }
    }
    if (click_rel(prm->event, prm->editor.texture_reset))
        prm->editor.deco_selected = -1;
}

void editor_update_enemy_stat(gen_t *prm)
{
    sfText_setString(prm->editor.hp_val, get_str
    (prm->editor.scenario->dictionnary[prm->editor.enemy_selected].hp));
    sfText_setString(prm->editor.armor_val, get_str
    (prm->editor.scenario->dictionnary[prm->editor.enemy_selected].armor));
    sfText_setString(prm->editor.range_val, get_str
    (prm->editor.scenario->dictionnary[prm->editor.enemy_selected].range));
    sfText_setString(prm->editor.speed_val, get_str
    (prm->editor.scenario->dictionnary[prm->editor.enemy_selected].speed));
    sfText_setString(prm->editor.nb_val, get_str
    (prm->editor.scenario->dictionnary[prm->editor.enemy_selected].number));
}

void taskbar_reset(gen_t *prm)
{
    sfSprite_setTextureRect(prm->editor.hitbox->sprite,
    get_intrect(0, 53, 53, 53));
    sfSprite_setTextureRect(prm->editor.enemies->sprite,
    get_intrect(0, 53, 53, 53));
    sfSprite_setTextureRect(prm->editor.spawnpoint->sprite,
    get_intrect(0, 53, 53, 53));
    sfSprite_setTextureRect(prm->editor.endpoint->sprite,
    get_intrect(0, 53, 53, 53));
}