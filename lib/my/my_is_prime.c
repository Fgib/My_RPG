/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    for (int i = 2; i < nb - 1; i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}