/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** draw_settings2
*/

#include "my_rpg.h"

void draw_settings_menu_text(gen_t *prm)
{
    sfRenderWindow_drawText(prm->window, prm->setting->transp->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->graphic_b->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->binding_b->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->sounds_b->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->gui_b->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->setting->menu_b->text, NULL);
}

void draw_settings_menu(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window, prm->setting->transp->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->graphic_b->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->binding_b->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->sounds_b->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->gui_b->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->setting->menu_b->sprite,
    NULL);
    draw_settings_menu_text(prm);
}

void draw_settings_sounds(gen_t *prm)
{
    sfText_setString(prm->setting->transp2->text, "Sounds Settings");
    sfRenderWindow_drawText(prm->window, prm->setting->transp2->text, NULL);

    draw_slider(prm->window, prm->setting->main_volume);
    draw_slider(prm->window, prm->setting->music);
    draw_slider(prm->window, prm->setting->effects);
    draw_slider(prm->window, prm->setting->ennemis);
    draw_slider(prm->window, prm->setting->alerts);
    draw_slider(prm->window, prm->setting->wind);
}

void draw_settings_gui(gen_t *prm)
{
    sfText_setString(prm->setting->transp2->text, "Interface Settings");
    sfRenderWindow_drawText(prm->window, prm->setting->transp2->text, NULL);
}