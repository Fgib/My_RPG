/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_settings
*/

#include "my_rpg.h"

void load_text_settings_keymap_coo(setti_menu_t *temp)
{
    sfText_setString(temp->t_up, "Move up");
    sfText_setString(temp->t_right, "Move right");
    sfText_setString(temp->t_down, "Move down");
    sfText_setString(temp->t_left, "Move left");
    sfText_setString(temp->t_atck , "Attack");
    sfText_setPosition(temp->t_up, get_vector(820, 359));
    sfText_setPosition(temp->t_right, get_vector(820, 439));
    sfText_setPosition(temp->t_down, get_vector(820, 519));
    sfText_setPosition(temp->t_left, get_vector(820, 599));
    sfText_setPosition(temp->t_atck, get_vector(820, 679));
}

void load_text_settings_keymap_b(setti_menu_t *temp)
{
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    temp->t_up = sfText_create();
    temp->t_right = sfText_create();
    temp->t_down = sfText_create();
    temp->t_left = sfText_create();
    temp->t_atck = sfText_create();
    sfText_setFont(temp->t_up, font);
    sfText_setFont(temp->t_right, font);
    sfText_setFont(temp->t_down, font);
    sfText_setFont(temp->t_left, font);
    sfText_setFont(temp->t_atck, font);
    load_text_settings_keymap_coo(temp);
}