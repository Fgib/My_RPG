/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_button
*/

#include "my_rpg.h"

struct button *initialize_button(vec_t coo, vec_t size, sfVector2f scale
, char *path)
{
    struct button *button_s = malloc(sizeof(struct button));

    button_s->coo = get_vector(coo.x, coo.y);
    button_s->size = get_vector(size.x, size.y);
    button_s->sprite = get_sprite(path);
    sfSprite_setPosition(button_s->sprite, get_vector(button_s->coo.x,
    button_s->coo.y));
    sfSprite_setScale(button_s->sprite, scale);
    return button_s;
}

void load_text_button(struct button *btn, vec3_t t_i, char *text)
{
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    btn->text = sfText_create();
    sfText_setString(btn->text, text);
    sfText_setFont(btn->text, font);
    sfText_setColor(btn->text, sfWhite);
    sfText_setCharacterSize(btn->text, t_i.z);
    sfText_setPosition(btn->text, get_vector(btn->coo.x + t_i.x,
    btn->coo.y + t_i.y));
}

sfText *load_text_str(char *str, int size, vec_t pos)
{
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    sfText *text;
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, get_vector(pos.x, pos.y));
    return text;
}

void load_icon_button(struct button *btn, char *path, vec_t coo
, sfVector2f size)
{
    btn->icon = get_sprite(path);
    sfSprite_setPosition(btn->icon, get_vector(btn->coo.x + coo.x,
    btn->coo.y + coo.y));
    sfSprite_setScale(btn->icon, get_vector(size.x, size.y));
}