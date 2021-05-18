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
    case 1: prm->keymap.forward = key;
        sfText_setString(me->go_up->text, char_to_str(key + 65));
        break;
    case 2: prm->keymap.right = key;
        sfText_setString(me->go_right->text, char_to_str(key + 65));
        break;
    case 3: prm->keymap.backward = key;
        sfText_setString(me->go_down->text, char_to_str(key + 65));
        break;
    case 4: prm->keymap.left = key;
        sfText_setString(me->go_left->text, char_to_str(key + 65));
        break;
    case 5: prm->keymap.inventory = key;
        //sfText_setString(me->go_up->text, char_to_str(key + 65));
        break;
    default: update_other(prm, me, key);
        break;
    }
}

void update_other(gen_t *prm, setti_menu_t *me, sfKeyCode key)
{
    switch (me->mapselect) {
    case 6: prm->keymap.space = key;
        //sfText_setString(me->go_right->text, char_to_str(key + 65));
        break;
    case 7: prm->keymap.interact = key;
        //sfText_setString(me->go_down->text, char_to_str(key + 65));
        break;
    case 8: prm->keymap.num1 = key;
        //sfText_setString(me->go_up->text, char_to_str(key + 65));
        break;
    case 9: prm->keymap.num2 = key;
        //sfText_setString(me->go_right->text, char_to_str(key + 65));
        break;
    case 10: prm->keymap.num3 = key;
        //sfText_setString(me->go_down->text, char_to_str(key + 65));
        break;
    default: update_num(prm, me, key);
        break;
    }
}

void update_num(gen_t *prm, setti_menu_t *me, sfKeyCode key)
{
    switch (me->mapselect) {
    case 11: prm->keymap.num4 = key;
        //sfText_setString(me->go_right->text, char_to_str(key + 65));
        break;
    case 12: prm->keymap.num5 = key;
        //sfText_setString(me->go_down->text, char_to_str(key + 65));
        break;
    case 13: prm->keymap.num6 = key;
        //sfText_setString(me->go_up->text, char_to_str(key + 65));
        break;
    case 14: prm->keymap.num7 = key;
        //sfText_setString(me->go_right->text, char_to_str(key + 65));
        break;
    case 15: prm->keymap.num8 = key;
        //sfText_setString(me->go_left->text, char_to_str(key + 65));
        break;
    case 16: prm->keymap.num9 = key;
        //sfText_setString(me->go_left->text, char_to_str(key + 65));
        break;
    }
}