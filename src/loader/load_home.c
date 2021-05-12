/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_home
*/

#include "my_rpg.h"

void load_home_struct_buttons(gen_t *prm)
{
    load_text_button(prm->home.transp, (vec3_t){25, 25, 40}, "My_RPG");
    load_text_button(prm->home.play_b, (vec3_t){25, 25, 40}, "Play");
    load_text_button(prm->home.edit_b, (vec3_t){25, 25, 40}, "Editor");
    load_text_button(prm->home.cstm_b, (vec3_t){25, 25, 40}, "Custom");
    load_text_button(prm->home.sett_b, (vec3_t){25, 25, 40}, "Settings");
    load_text_button(prm->home.abou_b, (vec3_t){25, 25, 40}, "About");
    load_text_button(prm->home.exit_b, (vec3_t){25, 25, 40}, "Exit");
}

void load_home_struct(gen_t *prm)
{
    prm->home.background = get_sprite("assets/back.png");
    prm->home.transp = initialize_button((vec_t){785, 280 - 80},
    (vec_t){0, 0}, (sfVector2f){2.25, 4.4}, "assets/tri_button.png");
    prm->home.play_b = initialize_button((vec_t){804, 350 - 60},
    (vec_t){250, 100}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    prm->home.edit_b = initialize_button((vec_t){804, 446 - 60},
    (vec_t){250, 100}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    prm->home.cstm_b = initialize_button((vec_t){804, 542 - 60},
    (vec_t){250, 100}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    prm->home.sett_b = initialize_button((vec_t){804, 638 - 60},
    (vec_t){250, 100}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    prm->home.abou_b = initialize_button((vec_t){804, 734 - 60},
    (vec_t){250, 100}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    prm->home.exit_b = initialize_button((vec_t){804, 830 - 60},
    (vec_t){250, 100}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    sfSprite_setTextureRect(prm->home.transp->sprite,
    get_intrect(0, 0, 156, 156));
    load_home_struct_buttons(prm);
}