/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** slider
*/

#include "my_rpg.h"

void slider_event(slider_t *slider, sfEvent event)
{
    int hit_x = event.mouseMove.x;
    int hit_y = event.mouseMove.y;

    if (hit_x >= slider->cursor->coo.x && hit_x <=
        slider->cursor->coo.x + slider->cursor->size.x / 2.0 && hit_y >=
        slider->cursor->coo.y && hit_y <= slider->cursor->coo.y +
        slider->cursor->size.y)
        slider->cursor->coo = get_vector(slider->cursor->coo.x > slider->coo.x
        ? event.mouseMove.x - slider->cursor->size.x / 2.0 : slider->coo.x,
        slider->cursor->coo.y);
    else if (hit_x >= slider->cursor->coo.x + slider->cursor->size.x / 2.0 &&
        hit_x <= slider->cursor->coo.x + slider->cursor->size.x && hit_y >=
        slider->cursor->coo.y && hit_y <= slider->cursor->coo.y +
        slider->cursor->size.y)
        slider->cursor->coo = get_vector(slider->cursor->coo.x <
        slider->coo.x + 300 ? event.mouseMove.x - slider->cursor->size.x/ 2.0 :
        slider->coo.x + 300, slider->cursor->coo.y);
}