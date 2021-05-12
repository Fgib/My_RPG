/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_editor
*/

#include "my_rpg.h"

void load_editor_deco_btn2(gen_t *prm)
{
    load_icon_button(prm->editor.deco_type[4],
    "assets/deco_tileset.png", (vec_t){18, 11}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[5],
    "assets/deco_tileset.png", (vec_t){21, 21}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[6],
    "assets/deco_tileset.png", (vec_t){25, 15}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[7],
    "assets/deco_tileset.png", (vec_t){25, 15}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[8],
    "assets/deco_tileset.png", (vec_t){18, 25}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[9],
    "assets/deco_tileset.png", (vec_t){18, 29}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[10],
    "assets/deco_tileset.png", (vec_t){35, 10}, get_vector(1, 1));
    load_icon_button(prm->editor.deco_type[11],
    "assets/deco_tileset.png", (vec_t){27, 10}, get_vector(0.25, 0.25));

}

void load_editor_deco_btn3(gen_t *prm)
{
    sfSprite_setTextureRect(prm->editor.deco_type[0]->icon, BANNER1);
    sfSprite_setTextureRect(prm->editor.deco_type[1]->icon, BANNER2);
    sfSprite_setTextureRect(prm->editor.deco_type[2]->icon, BARREL1);
    sfSprite_setTextureRect(prm->editor.deco_type[3]->icon, BARREL2);
    sfSprite_setTextureRect(prm->editor.deco_type[4]->icon, BARREL3);
    sfSprite_setTextureRect(prm->editor.deco_type[5]->icon, CRATE);
    sfSprite_setTextureRect(prm->editor.deco_type[6]->icon, POT1);
    sfSprite_setTextureRect(prm->editor.deco_type[7]->icon, POT2);
    sfSprite_setTextureRect(prm->editor.deco_type[8]->icon, SKELETON1);
    sfSprite_setTextureRect(prm->editor.deco_type[9]->icon, SKELETON2);
    sfSprite_setTextureRect(prm->editor.deco_type[10]->icon, TORCH);
    sfSprite_setTextureRect(prm->editor.deco_type[11]->icon, WINDOW);
}

void load_editor_deco_btn(gen_t *prm)
{
    prm->editor.deco_type = malloc(sizeof(struct button) * 12);

    for (int i = 0; i < 12; i++) {
        prm->editor.deco_type[i] =
        initialize_button((vec_t){15 + (i % 3 * 95), 260 + (i / 3 * 95)},
        (vec_t){93, 93}, get_vector(1.75, 1.75), "assets/cell.png");
        sfSprite_setTextureRect(prm->editor.deco_type[i]->sprite,
        get_intrect(0, 0, 53, 53));
    }
    load_icon_button(prm->editor.deco_type[0],
    "assets/deco_tileset.png", (vec_t){20, 10}, get_vector(0.3, 0.3));
    load_icon_button(prm->editor.deco_type[1],
    "assets/deco_tileset.png", (vec_t){25, 10}, get_vector(0.25, 0.2));
    load_icon_button(prm->editor.deco_type[2],
    "assets/deco_tileset.png", (vec_t){18, 11}, get_vector(0.25, 0.25));
    load_icon_button(prm->editor.deco_type[3],
    "assets/deco_tileset.png", (vec_t){18, 11}, get_vector(0.25, 0.25));
    load_editor_deco_btn2(prm);
    load_editor_deco_btn3(prm);
}

void editor_enemy_setup_loading2(gen_t *prm)
{
    prm->editor.hp_plus = initialize_button((vec_t){1400, 350},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.hp_moins = initialize_button((vec_t){1100, 350},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.armor_plus = initialize_button((vec_t){1400, 450},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.armor_moins = initialize_button((vec_t){1100, 450},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.range_plus = initialize_button((vec_t){1400, 550},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.range_moins = initialize_button((vec_t){1100, 550},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.speed_plus = initialize_button((vec_t){1400, 650},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.speed_moins = initialize_button((vec_t){1100, 650},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.nb_plus = initialize_button((vec_t){1400, 750},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
    prm->editor.nb_moins = initialize_button((vec_t){1100, 750},
    (vec_t){53, 53}, get_vector(1, 1), "assets/cell.png");
}

void editor_enemy_setup_loading3(gen_t *prm)
{
    load_text_button(prm->editor.hp_plus, (vec3_t){12, 0, 40}, "+");
    load_text_button(prm->editor.hp_moins, (vec3_t){20, 0, 40}, "-");
    load_text_button(prm->editor.armor_plus, (vec3_t){12, 0, 40}, "+");
    load_text_button(prm->editor.armor_moins, (vec3_t){20, 0, 40}, "-");
    load_text_button(prm->editor.range_plus, (vec3_t){12, 0, 40}, "+");
    load_text_button(prm->editor.range_moins, (vec3_t){20, 0, 40}, "-");
    load_text_button(prm->editor.speed_plus, (vec3_t){12, 0, 40}, "+");
    load_text_button(prm->editor.speed_moins, (vec3_t){20, 0, 40}, "-");
    load_text_button(prm->editor.nb_plus, (vec3_t){12, 0, 40}, "+");
    load_text_button(prm->editor.nb_moins, (vec3_t){20, 0, 40}, "-");
}