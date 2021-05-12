/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** generic
*/

#include "my_rpg.h"

void enemy_t_push(enemy_t **array, int *size, enemy_t new)
{
    enemy_t *buff = malloc(sizeof(**array) * ((*size) + 1));
    int i;

    for (i = 0; i < *size; ++i)
        buff[i] = (*array)[i];
    buff[i] = new;
    if (*size)
        free(*array);
    *array = buff;
    (*size)++;
}

void interactable_t_push(interactable_t **array, int *size, interactable_t new)
{
    interactable_t *buff = malloc(sizeof(**array) * ((*size) + 1));
    int i;
    for (i = 0; i < (*size); ++i)
        buff[i] = (*array)[i];
    buff[i] = new;
    if (*size)
        free(*array);
    *array = buff;
    (*size)++;
}

void enemy_t_delete_index(enemy_t **array, int *size, int index)
{
    enemy_t *buff = malloc(sizeof(**array) * ((*size) - 1));
    int i;
    int find = 0;
    for (i = 0; i < *size; ++i)
        if (i != index)
            buff[i - find] = (*array)[i];
        else
            find = 1;
    free(*array);
    *array = buff;
    (*size)--;
}