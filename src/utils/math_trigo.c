/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** trigo
*/

#include "my_rpg.h"

float tange(double x)
{
    double in_rad = x * M_PI / 180;
    return (tan(in_rad));
}

float cosinus(double x)
{
    double in_rad = x * M_PI / 180;
    return (cos(in_rad));
}

float sinus(double x)
{
    double in_rad = x * M_PI / 180;
    return (sin(in_rad));
}