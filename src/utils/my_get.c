/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_get
*/

#include "my_rpg.h"

sfSprite *get_sprite(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfIntRect get_intrect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = width;
    rect.left = left;
    rect.top = top;
    return (rect);
}

sfVector2f get_vector(double x, double y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

char *get_str(int val)
{
    int len = score_debugger(val);
    char *result = malloc(sizeof(char) * (len + 1));

    result[len] = '\0';
    while (len--) {
        result[len] = val %10 + 48;
        val = val / 10;
    }
    return (result);
}

int score_debugger(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}