/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_settings
*/

#include "my_rpg.h"

void setup_sub_settings(setti_menu_t *temp)
{
    temp->main_volume = initialize_slider(789, 350, 50, "Main Volume");
    temp->music = initialize_slider(789, 430, 50, "Musics");
    temp->effects = initialize_slider(789, 510, 50, "Effects");
    temp->ennemis = initialize_slider(789, 590, 50, "Enemies");
    temp->alerts = initialize_slider(789, 670, 50, "Alerts");
    temp->wind = initialize_slider(789, 750, 50, "Wind");
    temp->vsync = initialize_trigger((sfVector2f){804, 350}, "Vsync");
    temp->focus = initialize_trigger((sfVector2f){804, 420},
    "Pause on focus lost");
    temp->high_res = initialize_trigger((sfVector2f){804, 490},
    "High res textures");
    temp->luminosity = initialize_slider(789, 590, 50, "Luminosity");
    temp->contrast = initialize_slider(789, 670, 50, "Contrast");
    temp->saturation = initialize_slider(789, 750, 50, "Saturation");
}

void setup_settings_btns_text(setti_menu_t *temp)
{
    load_text_button(temp->transp, (vec3_t){20, 15, 40}, "Settings");
    load_text_button(temp->transp2, (vec3_t){20, 15, 40}, "Sub-Settings");
    load_text_button(temp->graphic_b, (vec3_t){20, 15, 40}, "Graphism");
    load_text_button(temp->binding_b, (vec3_t){20, 15, 40}, "Key-Binding");
    load_text_button(temp->sounds_b, (vec3_t){20, 15, 40}, "Sounds");
    load_text_button(temp->gui_b, (vec3_t){20, 15, 40}, "Interface");
    load_text_button(temp->menu_b, (vec3_t){20, 15, 40}, "Home");
}

void setup_settings_btns(setti_menu_t *temp)
{
    temp->transp = initialize_button((vec_t){385, 280},
    (vec_t){0, 0}, (sfVector2f){2.25, 3.7}, "assets/tri_button.png");
    temp->transp2 = initialize_button((vec_t){750, 234},
    (vec_t){0, 0}, (sfVector2f){3, 4}, "assets/tri_button.png");
    temp->graphic_b = initialize_button((vec_t){404, 350},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->binding_b = initialize_button((vec_t){404, 446},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->sounds_b = initialize_button((vec_t){404, 542},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->gui_b = initialize_button((vec_t){404, 638},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    temp->menu_b = initialize_button((vec_t){404, 734},
    (vec_t){312, 94}, (sfVector2f){2, 0.6}, "assets/tri_button.png");
    setup_settings_btns_text(temp);
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(temp->transp2->sprite, get_intrect(0, 0, 156, 156));
}

void load_settings_keymap(setti_menu_t *temp)
{
    temp->go_up = initialize_button((vec_t){1080, 350},
    (vec_t){60, 60}, (sfVector2f){0.45, 0.45}, "assets/tri_button.png");
    temp->go_right = initialize_button((vec_t){1080, 430},
    (vec_t){60, 60}, (sfVector2f){0.45, 0.45}, "assets/tri_button.png");
    temp->go_down = initialize_button((vec_t){1080, 510},
    (vec_t){60, 60}, (sfVector2f){0.45, 0.45}, "assets/tri_button.png");
    temp->go_left = initialize_button((vec_t){1080, 590},
    (vec_t){60, 60}, (sfVector2f){0.45, 0.45}, "assets/tri_button.png");
    temp->attack = initialize_button((vec_t){1080, 670},
    (vec_t){60, 60}, (sfVector2f){0.45, 0.45}, "assets/tri_button.png");
    load_text_button(temp->go_up, (vec3_t){20, 15, 40}, "W");
    load_text_button(temp->go_right, (vec3_t){20, 15, 40}, "D");
    load_text_button(temp->go_down, (vec3_t){20, 15, 40}, "S");
    load_text_button(temp->go_left, (vec3_t){20, 15, 40}, "A");
    load_text_button(temp->attack, (vec3_t){20, 15, 40}, "B");
}

setti_menu_t *load_settings_menu(void)
{
    setti_menu_t *temp = malloc(sizeof(setti_menu_t));

    temp->set_step = SET_HOME;
    temp->mapselect = 0;

    setup_sub_settings(temp);
    setup_settings_btns(temp);
    load_settings_keymap(temp);
    load_text_settings_keymap_b(temp);

    return temp;
}