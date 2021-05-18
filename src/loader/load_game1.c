/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_game
*/

#include "my_rpg.h"

void setup_bar(gen_t *prm)
{
    prm->game.lifebar.texture =
    sfTexture_createFromFile("assets/health_bar.png", NULL);
    prm->game.lifebar.coo = get_vector(480, 960);
    prm->game.lifebar.frame = sfSprite_create();
    prm->game.lifebar.bar = sfSprite_create();
    sfSprite_setTexture(prm->game.lifebar.frame,
    prm->game.lifebar.texture, sfTrue);
    sfSprite_setTextureRect(prm->game.lifebar.frame,
    get_intrect(0, 0, 960, 15));
    sfSprite_setTexture(prm->game.lifebar.bar,
    prm->game.lifebar.texture, sfTrue);
    sfSprite_setTextureRect(prm->game.lifebar.bar,
    get_intrect(15, 0, 960, 15));
    sfSprite_setPosition(prm->game.lifebar.frame, prm->game.lifebar.coo);
    sfSprite_setPosition(prm->game.lifebar.bar, prm->game.lifebar.coo);
    load_game_stats_up(prm);
}

void load_game_views(gen_t *prm)
{
    prm->game.last_mouse_pos = (vec_t){50, 50};
    prm->game.interface = sfView_createFromRect
    ((sfFloatRect){0, 0, 1920, 1080});
    prm->game.rendering = sfView_createFromRect
    ((sfFloatRect){0, 0, 1920, 1080});
}

void load_game_stats_up(gen_t *prm)
{
    prm->game.player->atk_plus = initialize_button((vec_t){900, 400}, (vec_t){26, 26}, get_vector(0.5, 0.5), "assets/tempo.png");
    prm->game.player->mv_speed_plus = initialize_button((vec_t){900, 475}, (vec_t){26, 26}, get_vector(0.5, 0.5), "assets/tempo.png");
    prm->game.player->atk_speed_plus = initialize_button((vec_t){900, 550}, (vec_t){26, 26}, get_vector(0.5, 0.5), "assets/tempo.png");
    load_text_button(prm->game.player->atk_plus)
    load_text_button(prm->game.player->mv_speed_plus)
    load_text_button(prm->game.player->atk_speed_plus)
}