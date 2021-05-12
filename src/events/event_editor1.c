/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event_editor
*/

#include "my_rpg.h"

void delete_enemy_btn(editor_t *edit, int index)
{
    for (int i = 0; i < edit->scenario->dic_count; i++) {
        free(edit->enemies_tab[i]);
    }
    free(edit->enemies_tab);

    enemy_t_delete_index(&edit->scenario->dictionnary,
    &edit->scenario->dic_count, index);

    edit->enemies_tab = malloc(sizeof(struct button) * 40);
    for (int i = 0; i < edit->scenario->dic_count; i++)
        edit->enemies_tab[i] = initialize_button((vec_t){380 + (i % 5 * 75),
            260 + (i / 5 * 75)}, (vec_t){60, 60}, get_vector(0.5, 0.5),
        "assets/Wenra/Button07.png");
    edit->enemies_tab[edit->scenario->dic_count] = initialize_button
    ((vec_t){375 + (edit->scenario->dic_count % 5 * 75), 260 +
        (edit->scenario->dic_count/ 5 * 75)}, (vec_t){60, 60},
    get_vector(0.5, 0.5), "assets/Wenra/Button08.png");

}

void view_movement(gen_t *prm)
{
    if (prm->keys.mv_up)
        prm->editor.cam_pos.y -= 5 *
        (prm->editor.zoom / 5 != 0 ? -prm->editor.zoom / 5 : 1);
    if (prm->keys.mv_down)
        prm->editor.cam_pos.y += 5 *
        (prm->editor.zoom / 5 != 0 ? -prm->editor.zoom / 5 : 1);
    if (prm->keys.mv_left)
        prm->editor.cam_pos.x -= 5 *
        (prm->editor.zoom / 5 != 0 ? -prm->editor.zoom / 5 : 1);
    if (prm->keys.mv_right)
        prm->editor.cam_pos.x += 5 *
        (prm->editor.zoom / 5 != 0 ? -prm->editor.zoom / 5 : 1);
}

void save_menu_event(gen_t *prm)
{
    if (prm->editor.edit_step == EXITING) {
        sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
        if (triforce(prm->event, prm->editor.retour))
            prm->editor.edit_step = DEFAULT;
        if (triforce(prm->event, prm->editor.exit_brut))
            prm->game_step = HOME;
        if (triforce(prm->event, prm->editor.exit_save)) {
            save(prm->editor.scenario);
            prm->game_step = HOME;
        }
    }
    if (prm->event.type == sfEvtKeyPressed &&
    prm->event.key.code == sfKeyEscape) {
        prm->editor.edit_step = EXITING;
    }
}