/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_revstr
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int char_lenght;
    int temp_var;

    char_lenght = my_strlen(str) - 1;
    for (int i = 0; i < char_lenght; i++) {
        temp_var = str[i];
        str[i] = str[char_lenght];
        str[char_lenght] = temp_var;
        char_lenght--;
    }
    return (str);
}
