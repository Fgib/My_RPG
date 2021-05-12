/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** draw_save_selector
*/

#include "my_rpg.h"

void draw_save_data(gen_t *prm, p_save_i *data)
{
    DRAW_T(data->level);
    DRAW_T(data->a_spd);
    DRAW_T(data->a_dmg);
    DRAW_T(data->m_spd);
}

void draw_save_selector(gen_t *prm)
{
    DRAW_S(prm->save_sel.choose->sprite);
    DRAW_T(prm->save_sel.choose->text);
    DRAW_S(prm->save_sel.save_one->sprite);
    DRAW_S(prm->save_sel.save_two->sprite);
    DRAW_S(prm->save_sel.save_tre->sprite);

    draw_save_data(prm, prm->save_sel.inf_one);
    draw_save_data(prm, prm->save_sel.inf_two);
    draw_save_data(prm, prm->save_sel.inf_tre);
}