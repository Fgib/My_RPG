/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_editor2
*/

#include "my_rpg.h"

void load_editor_enemies_list(gen_t *prm)
{
    prm->editor.enemies_tab = malloc(sizeof(struct button) * 40);
    for (int i = 0; i < prm->editor.scenario->dic_count; i++)
        prm->editor.enemies_tab[i] =
        initialize_button((vec_t){380 + (i % 5 * 75), 260 + (i / 5 * 75)},
        (vec_t){60, 60}, get_vector(0.5, 0.5), "assets/Wenra/Button07.png");
    prm->editor.enemies_tab[prm->editor.scenario->dic_count] =
    initialize_button((vec_t){375 + (prm->editor.scenario->dic_count % 5 * 75),
        260 + (prm->editor.scenario->dic_count/ 5 * 75)}, (vec_t){60, 60},
    get_vector(0.5, 0.5), "assets/Wenra/Button08.png");

    prm->editor.pen_type = malloc(sizeof(struct button) * 5);
    for (int i = 0; i < 5; i++) {
        prm->editor.pen_type[i] = initialize_button((vec_t){15 + 55 * i, 120},
        (vec_t){46, 46}, get_vector(0.3, 0.3), "assets/tri_button.png");
    }
}

void load_editor_deco_textures(gen_t *prm)
{
    prm->editor.liste_deco = malloc(sizeof(sfIntRect) * 12);
    prm->editor.liste_deco[0] = get_intrect(586 , 186, 185, 266);
    prm->editor.liste_deco[1] = get_intrect(336 , 0, 186, 394);
    prm->editor.liste_deco[2] = get_intrect(0 , 392, 231, 296);
    prm->editor.liste_deco[3] = get_intrect(0 , 623, 231, 296);
    prm->editor.liste_deco[4] = get_intrect(0 , 854, 231, 296);
    prm->editor.liste_deco[5] = get_intrect(336 , 186, 218, 250);
    prm->editor.liste_deco[6] = get_intrect(296 , 585, 181, 246);
    prm->editor.liste_deco[7] = get_intrect(296 , 404, 181, 245);
    prm->editor.liste_deco[8] = get_intrect(0 , 165, 227, 187);
    prm->editor.liste_deco[9] = get_intrect(187 , 165, 214, 149);
    prm->editor.liste_deco[10] = get_intrect(296 , 766, 28, 81);
    prm->editor.liste_deco[11] = get_intrect(0 , 0, 165, 300);
}

void load_editor_pen_selector(gen_t *prm)
{
    prm->editor.deco_selected = -1;
    load_editor_deco_btn(prm);
    load_icon_button(prm->editor.pen_type[0],
    "assets/icons/select.png", (vec_t){2, 2}, get_vector(0.082, 0.082));
    load_icon_button(prm->editor.pen_type[1],
    "assets/icons/floor.png", (vec_t){7, 7}, get_vector(0.13, 0.13));
    load_icon_button(prm->editor.pen_type[2],
    "assets/icons/wall.png", (vec_t){7, 7}, get_vector(0.13, 0.13));
    load_icon_button(prm->editor.pen_type[3],
    "assets/icons/deco.png", (vec_t){7, 7}, get_vector(0.13, 0.13));
    load_icon_button(prm->editor.pen_type[4],
    "assets/icons/items.png", (vec_t){7, 7}, get_vector(0.13, 0.13));
}

void load_editor_struct(gen_t *prm)
{
    load_editor_cursor_stuff(prm);
    load_editor_initialisation(prm);
    load_editor_gui(prm);
    load_editor_gui_tools(prm);
    load_editor_scenario_stuff(prm);
    load_editor_background(prm);
    load_editor_exit_menu(prm);
    load_editor_enemies_menu(prm);
    load_editor_enemies_list(prm);
    load_editor_deco_textures(prm);
    load_editor_pen_selector(prm);
    editor_enemy_setup_loading(prm);
}

void load_editor_enemies_menu(gen_t *prm)
{
    prm->editor.pop_info = initialize_button((vec_t){750, 150},
    (vec_t){39, 42}, get_vector(1, 1), "assets/Wenra/Close.png");
    load_icon_button(prm->editor.pop_info, "assets/Wenra/MainPanel02.png",
    (vec_t){-395, 15}, (sfVector2f){1.4, 1.8});
    load_text_button(prm->editor.pop_info, (vec3_t){-320, 40, 35},
    "Enemies list");
    prm->editor.pop_stat = initialize_button((vec_t){1500, 150},
    (vec_t){39, 42}, get_vector(1, 1), "assets/Wenra/Close.png");
    load_icon_button(prm->editor.pop_stat, "assets/Wenra/MainPanel02.png",
    (vec_t){-695, 15}, (sfVector2f){2.4, 1.8});
    load_text_button(prm->editor.pop_stat, (vec3_t){-490, 40, 35},
    "Enemy statistics");
    prm->editor.save_enemy_set = initialize_button((vec_t){1200, 830},
    (vec_t){140, 39}, get_vector(0.9, 0.25), "assets/tri_button.png");
    load_text_button(prm->editor.save_enemy_set, (vec3_t){30, 5, 25}, "SAVE");
}