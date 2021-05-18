/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_dispatch
*/

#include "my_rpg.h"

void manage_events_bis(gen_t *prm)
{
    switch ((int)prm->game_step) {
    case 2: events_save_selector(prm);
        break;
    case 6: pause_menu_event(prm);
        break;
    case 7: pause_menu_event(prm);
        break;
    case 8: settings_event(prm);
        break;
    }
}

void manage_events(gen_t *prm)
{
    keys_stuff(prm);
    if (prm->event.type == sfEvtClosed)
        sfRenderWindow_close(prm->window);
    switch ((int)prm->game_step) {
    case 0: home_event(prm);
        break;
    case 3: editor_events(prm);
        break;
    case 1: settings_event(prm);
        break;
    case 4: custom_events(prm);
        break;
    case 5: game_events(prm);
        break;
    default:
        manage_events_bis(prm);
    }
}