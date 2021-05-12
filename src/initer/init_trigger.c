/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_trigger
*/

#include "my_rpg.h"

struct trigger *initialize_trigger(sfVector2f pos, char *str)
{
    struct trigger *temp = malloc(sizeof(struct trigger));

    temp->coo = get_vector(1100, pos.y);
    temp->size = get_vector(28, 28);
    temp->state = 0;

    temp->sprite = get_sprite("assets/quad_btn.png");
    temp->check = get_sprite("assets/quad_btn.png");
    temp->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    sfSprite_setPosition(temp->sprite, temp->coo);
    sfSprite_setPosition(temp->check, temp->coo);
    sfSprite_setTextureRect(temp->sprite, get_intrect(0, 0, 28, 28));
    sfSprite_setTextureRect(temp->check, get_intrect(0, 112, 28, 28));

    sfText_setPosition(temp->text, get_vector(pos.x, pos.y));
    sfText_setCharacterSize(temp->text, 20);
    sfText_setString(temp->text, str);
    sfText_setFont(temp->text, font);

    return temp;
}