/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** free1
*/

#include "my_rpg.h"

void free_2dchar(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

void free_3dint(int ***arr)
{
    for (int j = 0; arr[j] != NULL; j++)
        for (int i = 0; arr[j][i] != NULL; i++)
            free(arr[j][i]);
    free(arr);
}