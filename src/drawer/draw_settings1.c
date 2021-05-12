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
    sfRenderWindow_drawText(prm->window, prm->setting->transp2->text, NULL);

    draw_trigger(prm->window, prm->setting->vsync);
    draw_trigger(prm->window, prm->setting->focus);
    draw_trigger(prm->window, prm->setting->high_res);
    draw_slider(prm->window, prm->setting->luminosity);
    draw_slider(prm->window, prm->setting->contrast);
    draw_slider(prm->window, prm->setting->saturation);
}

void draw_settings_keys_bis(gen_t *prm)
{
    sfRenderWindow_drawText(prm->window, prm->setting->t_up, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->t_right, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->t_down, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->t_left, NULL);
}

void draw_settings_keys(gen_t *prm)
{
    sfText_setString(prm->setting->transp2->text, "Keyboard Settings");
    sfRenderWindow_drawText(prm->window, prm->setting->transp2->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->setting->go_up->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->go_right->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->go_down->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->go_left->sprite,
    NULL);

    sfRenderWindow_drawText(prm->window, prm->setting->go_up->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->go_right->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->go_down->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->go_left->text, NULL);
}

void draw_settings(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    draw_settings_menu(prm);
    if (prm->setting->set_step != SET_HOME)
        sfRenderWindow_drawSprite(prm->window, prm->setting->transp2->sprite,
        NULL);
    if (prm->setting->set_step == SET_GRAPH)
        draw_settings_graph(prm);
    if (prm->setting->set_step == SET_KEYS)
        draw_settings_keys(prm);
    if (prm->setting->set_step == SET_SOUND)
        draw_settings_sounds(prm);
    if (prm->setting->set_step == SET_GUI)
        draw_settings_gui(prm);
}