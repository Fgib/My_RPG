/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int temp = 0;
    for (int i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
        temp = i;
    }
    dest[temp+1] = '\0';
    return (dest);
}
