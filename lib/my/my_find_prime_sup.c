/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int i = nb; i < 2 * nb; i++) {
        if (my_is_prime(i) == 1) {
            return (i);
        }
    }
    return 0;
}
