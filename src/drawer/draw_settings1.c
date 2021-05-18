/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_settings
*/

#include "my_rpg.h"

void draw_settings_graph(gen_t *prm)
{
    sfText_setString(prm->setting->transp2->text, "Graphics Settings");
    DRAW_T(prm->setting->transp2->text);

    draw_trigger(prm->window, prm->setting->vsync);
    draw_trigger(prm->window, prm->setting->focus);
    draw_trigger(prm->window, prm->setting->high_res);
    draw_slider(prm->window, prm->setting->luminosity);
    draw_slider(prm->window, prm->setting->contrast);
    draw_slider(prm->window, prm->setting->saturation);
}

void draw_settings_keys_bis(gen_t *prm)
{
    DRAW_T(prm->setting->t_up);
    DRAW_T(prm->setting->t_right);
    DRAW_T(prm->setting->t_down);
    DRAW_T(prm->setting->t_left);
    DRAW_T(prm->setting->t_atck);
}

void draw_settings_keys(gen_t *prm)
{
    sfText_setString(prm->setting->transp2->text, "Keyboard Settings");
    DRAW_T(prm->setting->transp2->text);
    DRAW_S(prm->setting->go_up->sprite);
    DRAW_S(prm->setting->go_right->sprite);
    DRAW_S(prm->setting->go_down->sprite);
    DRAW_S(prm->setting->go_left->sprite);
    DRAW_S(prm->setting->attack->sprite);
    DRAW_T(prm->setting->go_up->text);
    DRAW_T(prm->setting->go_right->text);
    DRAW_T(prm->setting->go_down->text);
    DRAW_T(prm->setting->go_left->text);
    DRAW_T(prm->setting->attack->text);
    draw_settings_keys_bis(prm);
}

void draw_settings(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    draw_settings_menu(prm);
    if (prm->setting->set_step != SET_HOME)
        DRAW_S(prm->setting->transp2->sprite);
    if (prm->setting->set_step == SET_GRAPH)
        draw_settings_graph(prm);
    if (prm->setting->set_step == SET_KEYS)
        draw_settings_keys(prm);
    if (prm->setting->set_step == SET_SOUND)
        draw_settings_sounds(prm);
    if (prm->setting->set_step == SET_GUI)
        draw_settings_gui(prm);
}