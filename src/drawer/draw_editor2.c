/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** draw_editor2
*/

#include "my_rpg.h"

void draw_editor_print_gui(gen_t *prm)
{
    DRAW_S(prm->editor.bar);
    DRAW_S(prm->editor.select);
    DRAW_S(prm->editor.enemies->sprite);
    DRAW_S(prm->editor.hitbox->sprite);
    DRAW_S(prm->editor.spawnpoint->sprite);
    DRAW_S(prm->editor.endpoint->sprite);
    DRAW_T(prm->editor.hitbox->text);
    DRAW_T(prm->editor.spawnpoint->text);
    DRAW_T(prm->editor.endpoint->text);
    DRAW_T(prm->editor.enemies->text);
    draw_simplified_slider(prm->window, prm->editor.zones_selector);
    DRAW_S(prm->editor.hide_zones->sprite);
    DRAW_T(prm->editor.hide_zones->text);
    for (int i = 0; i < 5; i++) {
        DRAW_S(prm->editor.pen_type[i]->sprite);
        DRAW_S(prm->editor.pen_type[i]->icon);
    }
}

void draw_editor_enemies_tabs(gen_t *prm)
{
    DRAW_S(prm->editor.pop_info->icon);
    DRAW_S(prm->editor.pop_info->sprite);
    DRAW_T(prm->editor.pop_info->text);
    for (int i = 0; i < prm->editor.scenario->dic_count + 1; i++)
        DRAW_S(prm->editor.enemies_tab[i]->sprite);
}

void draw_editor_enemies_stats_text(gen_t *prm)
{
    DRAW_T(prm->editor.pop_stat->text);
    DRAW_T(prm->editor.save_enemy_set->text);
    DRAW_T(prm->editor.hp_plus->text);
    DRAW_T(prm->editor.hp_moins->text);
    DRAW_T(prm->editor.hp_val);
    DRAW_T(prm->editor.armor_plus->text);
    DRAW_T(prm->editor.armor_moins->text);
    DRAW_T(prm->editor.armor_val);
    DRAW_T(prm->editor.range_plus->text);
    DRAW_T(prm->editor.range_moins->text);
    DRAW_T(prm->editor.range_val);
    DRAW_T(prm->editor.speed_plus->text);
    DRAW_T(prm->editor.speed_moins->text);
    DRAW_T(prm->editor.speed_val);
    DRAW_T(prm->editor.nb_plus->text);
    DRAW_T(prm->editor.nb_moins->text);
    DRAW_T(prm->editor.nb_val);
}

void draw_editor_enemies_stats_text2(gen_t *prm)
{
    DRAW_T(prm->editor.hp_text->text);
    DRAW_T(prm->editor.armor_text->text);
    DRAW_T(prm->editor.range_text->text);
    DRAW_T(prm->editor.speed_text->text);
    DRAW_T(prm->editor.nb_text->text);
}

void draw_editor_enemies_stats(gen_t *prm)
{
    DRAW_S(prm->editor.pop_stat->icon);
    DRAW_S(prm->editor.pop_stat->sprite);
    DRAW_S(prm->editor.save_enemy_set->sprite);
    DRAW_S(prm->editor.hp_plus->sprite);
    DRAW_S(prm->editor.hp_moins->sprite);
    DRAW_S(prm->editor.armor_plus->sprite);
    DRAW_S(prm->editor.armor_moins->sprite);
    DRAW_S(prm->editor.range_plus->sprite);
    DRAW_S(prm->editor.range_moins->sprite);
    DRAW_S(prm->editor.speed_plus->sprite);
    DRAW_S(prm->editor.speed_moins->sprite);
    DRAW_S(prm->editor.nb_plus->sprite);
    DRAW_S(prm->editor.nb_moins->sprite);
    draw_editor_enemies_stats_text(prm);
    draw_editor_enemies_stats_text2(prm);
}