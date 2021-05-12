/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** drawer_utils
*/

#include "my_rpg.h"

void draw_slider(sfRenderWindow *window, struct slider *slider)
{
    slider->value = (slider->cursor->coo.x - slider->coo.x) / 3;
    sfSprite_setScale(slider->bar_filled, get_vector(slider->value / 103.0, 1));
    sfSprite_setPosition(slider->cursor->sprite, slider->cursor->coo);
    sfText_setString(slider->digit, get_str(slider->value));

    sfRenderWindow_drawSprite(window, slider->bar_empty, NULL);
    sfRenderWindow_drawSprite(window, slider->bar_filled, NULL);
    sfRenderWindow_drawSprite(window, slider->p_box, NULL);
    sfRenderWindow_drawSprite(window, slider->cursor->sprite, NULL);

    sfRenderWindow_drawText(window, slider->text, NULL);
    sfRenderWindow_drawText(window, slider->digit, NULL);
}

void draw_trigger(sfRenderWindow *window, struct trigger *trigger)
{
    sfRenderWindow_drawText(window, trigger->text, NULL);
    sfRenderWindow_drawSprite(window, trigger->sprite, NULL);
    if (trigger->state) {
        sfRenderWindow_drawSprite(window, trigger->check, NULL);
    }
}

void draw_simplified_slider(sfRenderWindow *window, struct slider *slider)
{
    slider->value = (slider->cursor->coo.x - slider->coo.x) / 3;
    sfSprite_setScale(slider->bar_filled, get_vector(slider->value / 103.0, 1));
    sfSprite_setPosition(slider->cursor->sprite, slider->cursor->coo);
    sfText_setString(slider->digit, get_str(slider->value * 14 / 100 + 1));
    sfRenderWindow_drawSprite(window, slider->bar_empty, NULL);
    sfRenderWindow_drawSprite(window, slider->bar_filled, NULL);
    sfRenderWindow_drawSprite(window, slider->p_box, NULL);
    sfRenderWindow_drawSprite(window, slider->cursor->sprite, NULL);
    sfRenderWindow_drawText(window, slider->text, NULL);
    sfRenderWindow_drawText(window, slider->digit, NULL);
}