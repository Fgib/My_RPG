/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_strstr
*/

int my_strlen(char *str);

char *my_strstr(char *str, char *to_find)
{
    int searched_size = my_strlen(to_find);
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[j]) {
            j++;
        } else if (j == searched_size) {
            return (&str[i - searched_size]);
        } else {
            j = 0;
        }
    }
    return (0);
}