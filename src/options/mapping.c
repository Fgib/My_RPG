/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** keymapping
*/

#include "my_rpg.h"

void update_keys(gen_t *prm, setti_menu_t *me, sfKeyCode key)
{
    if (!me->mapselect)
        return;
    switch (me->mapselect) {
    case 1: prm->keymap->w = key;
        sfText_setString(me->go_up->text, char_to_str(key + 65));
        break;
    case 2: prm->keymap->d = key;
        sfText_setString(me->go_right->text, char_to_str(key + 65));
        break;
    case 3: prm->keymap->s = key;
        sfText_setString(me->go_down->text, char_to_str(key + 65));
        break;
    case 4: prm->keymap->a = key;
        sfText_setString(me->go_left->text, char_to_str(key + 65));
        break;
    default:
        break;
    }
}