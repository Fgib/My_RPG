/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 || str[i] > 57) && str[i] != '\n') {
            return (0);
        }
    }
    return (1);
}