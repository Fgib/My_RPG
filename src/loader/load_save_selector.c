/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_save_selector
*/

#include "my_rpg.h"

void load_selector_save_data_bis(int i, player_t *data, p_save_i *temp)
{
    sfText_setPosition(temp->level, get_vector(i, 300));
    sfText_setString(temp->level, str_add("Level : ",
    get_str(data->stats.level)));
    sfText_setPosition(temp->a_dmg, get_vector(i, 400));
    sfText_setString(temp->a_dmg, str_add("Damage : ",
    get_str(data->stats.damage)));
    sfText_setPosition(temp->a_spd, get_vector(i, 500));
    sfText_setString(temp->a_spd, str_add("Atk speed : ",
    get_str(data->stats.mov_speed)));
    sfText_setPosition(temp->m_spd, get_vector(i, 600));
    sfText_setString(temp->m_spd, str_add("Mov speed : ",
    get_str(data->stats.atk_speed)));
}

p_save_i *load_selector_save_data(int i, player_t *data)
{
    p_save_i *temp = malloc(sizeof(p_save_i));
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    temp->level = sfText_create();
    sfText_setFont(temp->level, font);
    temp->a_dmg = sfText_create();
    sfText_setFont(temp->a_dmg, font);
    temp->a_spd = sfText_create();
    sfText_setFont(temp->a_spd, font);
    temp->m_spd = sfText_create();
    sfText_setFont(temp->m_spd, font);
    load_selector_save_data_bis(i, data, temp);
    return temp;
}

void load_save_selector(gen_t *prm)
{
    prm->save_sel.selected = -1;
    prm->save_sel.choose = initialize_button((vec_t){890, 1000},
    (vec_t){140, 39}, get_vector(0.9, 0.25), "assets/tri_button.png");
    load_text_button(prm->save_sel.choose, (vec3_t){15, 5, 25}, "CHOOSE");
    prm->save_sel.save_one = initialize_button((vec_t){240, 200},
    (vec_t){466, 702}, get_vector(2.987, 4.5), "assets/tri_button.png");
    prm->save_sel.save_two = initialize_button((vec_t){726, 200},
    (vec_t){466, 702}, get_vector(2.987, 4.5), "assets/tri_button.png");
    prm->save_sel.save_tre = initialize_button((vec_t){1212, 200},
    (vec_t){466, 702}, get_vector(2.987, 4.5), "assets/tri_button.png");
    prm->saves.save = "player->saves";
    prm->save_sel.inf_one = load_selector_save_data(240, &prm->saves.save1);
    prm->save_sel.inf_two = load_selector_save_data(726, &prm->saves.save2);
    prm->save_sel.inf_tre = load_selector_save_data(1212, &prm->saves.save3);
}