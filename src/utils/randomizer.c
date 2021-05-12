/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** randomizer
*/

#include "my_rpg.h"

int random_gen(int min, int max)
{
    int result;
    int low_num = 0;
    int hig_num = 0;

    if (min < max) {
        low_num = min;
        hig_num = max + 1;
    } else {
        low_num = min + 1;
        hig_num = min;
    }
    result = rand() % (hig_num - low_num) + low_num;
    return (result);
}