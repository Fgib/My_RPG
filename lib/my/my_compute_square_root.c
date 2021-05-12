/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return (0);
    for (int i = 1; i < 46342; i++) {
        if (i * i == nb) {
            return (i);
        }
    }
    return (0);
}