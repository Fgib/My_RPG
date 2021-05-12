/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char *src)
{
    int temp;

    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        temp = i;
    }
    dest[temp + 1] = '\0';
    return (dest);
}