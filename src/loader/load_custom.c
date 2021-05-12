/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_custom
*/

#include "my_rpg.h"

void load_custom_color(gen_t *prm)
{
    prm->custom.expl = get_sprite("assets/blank_tile.png");
    sfSprite_setPosition(prm->custom.expl, get_vector(832, 220));
    prm->custom.color = (sfColor){prm->custom.red->value * 2.55,
        prm->custom.green->value * 2.55, prm->custom.blue->value * 2.55, 255};
    sfSprite_setColor(prm->custom.expl, prm->custom.color);
}

void load_custom_struct(gen_t *prm)
{
    prm->custom.transp = initialize_button((vec_t){745, 200},
    (vec_t){0, 0}, (sfVector2f){2.75, 4.4}, "assets/tri_button.png");
    load_text_button(prm->custom.transp, (vec3_t){25, 25, 40},
    "Customization");
    sfSprite_setTextureRect(prm->custom.transp->sprite,
    get_intrect(0, 0, 156, 156));

    prm->custom.save = initialize_button((vec_t){890, 810},
    (vec_t){140, 39}, get_vector(0.9, 0.25), "assets/tri_button.png");
    load_text_button(prm->custom.save, (vec3_t){30, 5, 25}, "SAVE");

    prm->custom.red = initialize_slider(760, 500, 50, "Red");
    prm->custom.green = initialize_slider(760, 600, 50, "Green");
    prm->custom.blue = initialize_slider(760, 700, 50, "Blue");
    load_custom_color(prm);
}