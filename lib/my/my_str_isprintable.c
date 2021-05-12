/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32 || str[i] > 126) {
            return (0);
        }
    }
    return (1);
}