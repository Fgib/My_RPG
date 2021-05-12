/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int temp_var;

    temp_var = *a;
    *a = *b;
    *b = temp_var;
}
