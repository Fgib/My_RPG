/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-florian.gibault
** File description:
** load_game2
*/

#include "my_rpg.h"

void load_game_buttons(gen_t *prm)
{
    prm->game.inv_btn = malloc(sizeof(struct button) * 36);
    for (int i = 0; i < 27; i++) {
        prm->game.inv_btn[i] = initialize_button((vec_t){710 + i % 9 * 56,
            520 + i / 9 * 56 + (i / 9 == 3 ? 25 : 0)}, (vec_t){53, 53},
        get_vector(1, 1), "assets/cell.png");
        sfSprite_setTextureRect(prm->game.inv_btn[i]->sprite,
        get_intrect(0, 0, 53, 53));
        load_text_button(prm->game.inv_btn[i], (vec3_t){5, 43, 10}, "1");
    }
    for (int i = 27; i < 36; i++) {
        prm->game.inv_btn[i] =
        initialize_button((vec_t){585 + i % 9 * 84, 1000}, (vec_t){53, 53},
        get_vector(1, 1), "assets/cell.png");
        sfSprite_setScale(prm->game.inv_btn[i]->sprite, get_vector(1.5, 1.5));
        sfSprite_setTextureRect(prm->game.inv_btn[i]->sprite,
        get_intrect(0, 0, 53, 53));
        load_text_button(prm->game.inv_btn[i], (vec3_t){5, 43, 10}, "1");
    }
    setup_bar(prm);
}

void load_game_particle(gen_t *prm)
{
    prm->game.part_l = malloc(sizeof(parti_c) * 5);
    prm->game.part_l[0].core = get_sprite("assets/hero&weapon/heal_spell.png");
    sfSprite_setScale(prm->game.part_l[0].core, get_vector(3, 3));
    prm->game.part_l[0].lifetime = -1;
    prm->game.part_l[1].core = get_sprite("assets/hero&weapon/fire_spell.png");
    sfSprite_setColor(prm->game.part_l[1].core, prm->custom.color);
    sfSprite_setScale(prm->game.part_l[1].core, get_vector(3, 3));
    prm->game.part_l[1].lifetime = -1;
}

void load_game_scenario(gen_t *prm)
{
    prm->game.scenario.path = "first_scenario.scen";
    prm->game.scenario.row_data = my_str_splitter
    (my_file_loader(prm->game.scenario.path), '\n');
    prm->game.scenario.name = "Joli Nom";
    get_dictionnary(&prm->game.scenario);
    if (!get_map(prm, &prm->game.scenario)) {
        prm->game_step = HOME;
        return;
    }
    if (!get_positions(&prm->game.scenario))
        write(1, "Error when loading player pos\n", 30);
}

void load_game_struct(gen_t *prm)
{
    init_player(prm);
    prm->game.zoom = 0;
    prm->game.g_status = PLAY;
    load_game_views(prm);
    load_game_scenario(prm);
    NVECTOR(prm->game.player->coo, prm->game.scenario.start.x * 256,
    prm->game.scenario.start.y * 256);
    load_enemies(&prm->game.scenario);
    load_game_buttons(prm);
    prm->game.inv_tansp = initialize_button((vec_t){690, 330},
    (vec_t){0, 0}, get_vector(3.47, 3), "assets/tri_button.png");
    sfSprite_setTextureRect(prm->game.inv_tansp->sprite,
    get_intrect(0, 0, 156, 156));
    load_game_particle(prm);
}