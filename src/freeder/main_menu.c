/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** main_menu
*/

#include "my_rpg.h"

void free_sfButton(struct button *button)
{
    sfText_destroy(button->text);
    sfSprite_destroy(button->sprite);
    free(button);
}

void free_main_menu(gen_t *prm)
{
    sfSprite_destroy(prm->home.background);
    free_sfButton(prm->home.transp);
    free_sfButton(prm->home.play_b);
    free_sfButton(prm->home.edit_b);
    free_sfButton(prm->home.cstm_b);
    free_sfButton(prm->home.sett_b);
    free_sfButton(prm->home.abou_b);
    free_sfButton(prm->home.exit_b);
}

