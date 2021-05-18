/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event_settings
*/

#include "my_rpg.h"

void events_sub_settings_graph(gen_t *prm)
{
    if (prm->setting->set_step == SET_GRAPH) {
        trigger_event(prm->setting->vsync, prm->event);
        trigger_event(prm->setting->focus, prm->event);
        trigger_event(prm->setting->high_res, prm->event);
        if (prm->keys.mouse) {
            slider_event(prm->setting->luminosity, prm->event);
            slider_event(prm->setting->contrast, prm->event);
            slider_event(prm->setting->saturation, prm->event);
        }
    }
}

void events_sub_settings_sound(gen_t *prm)
{
    if (prm->keys.mouse && prm->setting->set_step == SET_SOUND) {
        slider_event(prm->setting->main_volume, prm->event);
        slider_event(prm->setting->music, prm->event);
        slider_event(prm->setting->effects, prm->event);
        slider_event(prm->setting->ennemis, prm->event);
        slider_event(prm->setting->alerts, prm->event);
        slider_event(prm->setting->wind, prm->event);
    }
}

void events_sub_settings_keys(gen_t *prm)
{
    if (prm->setting->set_step == SET_KEYS) {
        if (triforce(prm->event, prm->setting->go_up))
            prm->setting->mapselect = 1;
        if (triforce(prm->event, prm->setting->go_right))
            prm->setting->mapselect = 2;
        if (triforce(prm->event, prm->setting->go_down))
            prm->setting->mapselect = 3;
        if (triforce(prm->event, prm->setting->go_left))
            prm->setting->mapselect = 4;
        triforce(prm->event, prm->setting->attack);
        if (prm->event.type == sfEvtKeyPressed && prm->setting->mapselect)
            update_keys(prm, prm->setting, prm->event.key.code);
    }
}

void settings_event(gen_t *prm)
{
    if (triforce(prm->event, prm->setting->graphic_b))
        prm->setting->set_step = SET_GRAPH;
    if (triforce(prm->event, prm->setting->binding_b))
        prm->setting->set_step = SET_KEYS;
    if (triforce(prm->event, prm->setting->sounds_b))
        prm->setting->set_step = SET_SOUND;
    if (triforce(prm->event, prm->setting->gui_b))
        prm->setting->set_step = SET_GUI;
    if (triforce(prm->event, prm->setting->menu_b)) {
        prm->setting->set_step = SET_HOME;
        prm->game_step = HOME;
    }
    events_sub_settings_graph(prm);
    events_sub_settings_sound(prm);
    events_sub_settings_keys(prm);
}