/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** event_editor3
*/

#include "my_rpg.h"

void editor_events_taskbar_bis(gen_t *prm)
{
    if (click_rel(prm->event, prm->editor.spawnpoint)) {
        taskbar_reset(prm);
        sfSprite_setTextureRect(prm->editor.spawnpoint->sprite,
        get_intrect(0, 0, 53, 53));
        prm->editor.edit_step = DEFAULT;
        prm->editor.pmod = SPAWN;
    }
    if (click_pre(prm->event, prm->editor.zones_selector->cursor)) {
        taskbar_reset(prm);
        prm->editor.pmod = ZONES;
        prm->editor.texture_locked = -1;
    }
}

void editor_events_taskbar(gen_t *prm)
{
    taskbar_reset(prm);
    if (click_rel(prm->event, prm->editor.hitbox)) {
        taskbar_reset(prm);
        sfSprite_setTextureRect(prm->editor.hitbox->sprite,
        get_intrect(0, 0, 53, 53));
        prm->editor.edit_step = DEFAULT;
        prm->editor.pmod = HITBOX;
    }
    if (click_rel(prm->event, prm->editor.enemies)) {
        taskbar_reset(prm);
        sfSprite_setTextureRect(prm->editor.enemies->sprite,
        get_intrect(0, 0, 53, 53));
        prm->editor.edit_step = ENEMIES_INFO;
        prm->editor.pmod = SELECT;
    }
    editor_events_taskbar_bis(prm);
}

void editor_enemy_stat_event_plus(gen_t *prm)
{
    if (duoforce(prm->event, prm->editor.hp_plus, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].hp++;
    if (duoforce(prm->event, prm->editor.armor_plus, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].armor++;
    if (duoforce(prm->event, prm->editor.range_plus, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].range++;
    if (duoforce(prm->event, prm->editor.speed_plus, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].speed++;
    if (duoforce(prm->event, prm->editor.nb_plus, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].number++;
}

void editor_enemy_stat_event_moins(gen_t *prm)
{
    if (duoforce(prm->event, prm->editor.hp_moins, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].hp--;
    if (duoforce(prm->event, prm->editor.armor_moins, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].armor--;
    if (duoforce(prm->event, prm->editor.range_moins, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].range--;
    if (duoforce(prm->event, prm->editor.speed_moins, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].speed--;
    if (duoforce(prm->event, prm->editor.nb_moins, 53))
        prm->editor.scenario->dictionnary[prm->editor.enemy_selected].number--;
}

void editor_enemy_stat_event(gen_t *prm)
{
    editor_enemy_stat_event_plus(prm);
    editor_enemy_stat_event_moins(prm);
    if (click_rel(prm->event, prm->editor.pop_stat))
        prm->editor.edit_step = ENEMIES_INFO;
    if (triforce(prm->event, prm->editor.save_enemy_set))
        prm->editor.edit_step = ENEMIES_INFO;
    editor_update_enemy_stat(prm);
}