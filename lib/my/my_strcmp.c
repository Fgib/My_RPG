/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (s2[i] - s1[i]);
        }
    }
    return 0;
}