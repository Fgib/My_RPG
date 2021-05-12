/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}