/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "my_rpg.h"

void dispose(gen_t *prm)
{
    write(1, "Free begining\n", 14);
    sfRenderWindow_destroy(prm->window);
    free(prm);
    write(1, "Successfully free\n", 18);
}

void refresh_window(gen_t *prm)
{
    sfRenderWindow_clear(prm->window, sfBlack);
    window_update(prm);
    sfRenderWindow_display(prm->window);
}

void game_calculation(gen_t *prm)
{
    if (prm->game_step == GAME) {
        player_movement(prm);
        player_animation(prm);
        enemies_movement(prm);
    }
}

int main(void)
{
    gen_t *prm = get_struct_settings();

    sfRenderWindow_setFramerateLimit(prm->window, 60);
    while (sfRenderWindow_isOpen(prm->window) && prm->game_step != OUT) {
        while (sfRenderWindow_pollEvent(prm->window, &prm->event)) {
            manage_events(prm);
        }
        if (sfClock_getElapsedTime(prm->animation_clock).microseconds >
        1000000 / 44) {
            game_calculation(prm);
            refresh_window(prm);
        }
    }
    dispose(prm);
    return 0;
}