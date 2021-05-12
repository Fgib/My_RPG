/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_home
*/

#include "my_rpg.h"

void draw_home(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window, prm->home.background, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.transp->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.transp->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.play_b->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.play_b->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.edit_b->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.edit_b->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.cstm_b->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.cstm_b->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.sett_b->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.sett_b->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.abou_b->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.abou_b->text, NULL);

    sfRenderWindow_drawSprite(prm->window, prm->home.exit_b->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->home.exit_b->text, NULL);

}