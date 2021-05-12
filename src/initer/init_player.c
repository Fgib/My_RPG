/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** init_player
*/

#include "my_rpg.h"


void setup_player_text(player_t *ply)
{
    ply->stats.xp_t = sfText_create();
    sfText_setPosition(ply->stats.xp_t, get_vector(1000, 460));
    sfText_setColor(ply->stats.xp_t, (sfColor){0, 0, 0, 255});
    sfText_setCharacterSize(ply->stats.xp_t, 20);
    sfText_setString(ply->stats.xp_t, str_add("Xp :",
    str_add(get_str(ply->stats.xp), str_add("/",
    get_str(ply->stats.xp_next)))));
    ply->stats.level_t = sfText_create();
    sfText_setPosition(ply->stats.level_t, get_vector(1000, 360));
    sfText_setColor(ply->stats.level_t, (sfColor){0, 0, 0, 255});
    sfText_setCharacterSize(ply->stats.level_t, 20);
    sfText_setString(ply->stats.level_t, str_add("Level : ",
    get_str(ply->stats.level)));
}

void setup_player_text_bis(player_t *ply)
{
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    ply->stats.mov_speed_t = sfText_create();
    ply->stats.atk_speed_t = sfText_create();
    ply->stats.damage_t = sfText_create();
    sfText_setFont(ply->stats.atk_speed_t, font);
    sfText_setFont(ply->stats.mov_speed_t, font);
    sfText_setFont(ply->stats.damage_t, font);
    sfText_setPosition(ply->stats.mov_speed_t, get_vector(800, 357));
    sfText_setPosition(ply->stats.atk_speed_t, get_vector(800, 410));
    sfText_setPosition(ply->stats.damage_t, get_vector(800, 460));
    sfText_setColor(ply->stats.damage_t, (sfColor){0, 0, 0, 255});
    sfText_setColor(ply->stats.mov_speed_t, (sfColor){0, 0, 0, 255});
    sfText_setColor(ply->stats.atk_speed_t, (sfColor){0, 0, 0, 255});
    sfText_setString(ply->stats.damage_t, get_str(ply->stats.damage));
    sfText_setString(ply->stats.mov_speed_t, get_str(ply->stats.mov_speed));
    sfText_setString(ply->stats.atk_speed_t, get_str(ply->stats.atk_speed));
    sfText_setFont(ply->stats.level_t, font);
    sfText_setFont(ply->stats.xp_t, font);
}

void get_player_stats(player_t *ply)
{
    ply->skin_id = 0;
    ply->dir = 0;
    ply->fly = 0;
    ply->gmode = 0;
    ply->vision = 5;
    ply->attack_id = 0;
}

void select_player(gen_t *prm, int nbr)
{
    switch (nbr) {
    case 0: prm->game.player = &prm->saves.save1;
        break;
    case 1: prm->game.player = &prm->saves.save2;
        break;
    case 2: prm->game.player = &prm->saves.save3;
        break;
    }
}

void init_player(gen_t *prm)
{
    select_player(prm, prm->save_sel.selected);
    prm->game.player->player_sheet =
    get_sprite("assets/hero&weapon/champion/paysan.png");
    sfSprite_setTextureRect(prm->game.player->player_sheet,
    get_intrect(0, 0, 64, 64));
    sfSprite_setOrigin(prm->game.player->player_sheet, get_vector(32, 60));
    sfSprite_setScale(prm->game.player->player_sheet, get_vector(4, 4));
    prm->game.player->stats_icon = get_sprite("assets/stats.png");
    sfSprite_setPosition(prm->game.player->stats_icon, get_vector(700, 340));
    sfSprite_setScale(prm->game.player->stats_icon, get_vector(3, 3));
    sfSprite_setColor(prm->game.player->stats_icon, (sfColor){0, 0, 0, 255});
    get_player_stats(prm->game.player);
    setup_player_text(prm->game.player);
    setup_player_text_bis(prm->game.player);
}