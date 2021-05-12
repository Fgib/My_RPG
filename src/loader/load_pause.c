/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_pause
*/

#include "my_rpg.h"

void load_pause_save_verif(struct pause_menu *temp)
{
    temp->transp2 = initialize_button((vec_t){785, 280}, (vec_t){0, 0},
    (sfVector2f){2.25, 3}, "assets/tri_button.png");
    temp->save_y = initialize_button((vec_t){795, 290}, (vec_t){0, 0},
    (sfVector2f){1, 1}, "assets/tri_button.png");
    temp->save_n = initialize_button((vec_t){950, 290}, (vec_t){0, 0},
    (sfVector2f){1, 1}, "assets/tri_button.png");
    load_text_button(temp->transp2, (vec3_t){15, 15, 30}, "Would you save ?");
    load_text_button(temp->save_y, (vec3_t){20, 15, 40}, "YES");
    load_text_button(temp->save_n, (vec3_t){20, 15, 40}, "NO");
}

void load_pause_buttons(struct pause_menu *temp)
{
    load_text_button(temp->transp, (vec3_t){20, 15, 40}, "Pause");
    load_text_button(temp->resume_b, (vec3_t){76, 22, 40}, "Resume");
    load_text_button(temp->restart_b, (vec3_t){80, 22, 40}, "Restart");
    load_text_button(temp->settings_b, (vec3_t){72, 22, 40}, "Settings");
    load_text_button(temp->menu_b, (vec3_t){95, 22, 40}, "Home");
    load_text_button(temp->exit_b, (vec3_t){115, 22, 40}, "Exit");
}

struct pause_menu *get_pause_s(void)
{
    struct pause_menu *temp = malloc(sizeof(struct pause_menu));

    temp->calc = get_sprite("assets/pause_calc.png");
    temp->transp = initialize_button((vec_t){785, 280},
    (vec_t){0, 0}, (sfVector2f){2.25, 3.7}, "assets/tri_button.png");
    temp->resume_b = initialize_button((vec_t){804, 350},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->restart_b = initialize_button((vec_t){804, 446},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->settings_b = initialize_button((vec_t){804, 542},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->menu_b = initialize_button((vec_t){804, 638},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->exit_b = initialize_button((vec_t){804, 734},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    load_pause_buttons(temp);
    load_pause_save_verif(temp);

    return temp;
}