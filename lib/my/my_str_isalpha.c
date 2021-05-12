/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122)) {
            return (0);
        }
    }
    return (1);
}