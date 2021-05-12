/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_getnbr
*/

int my_strlen(char const *str);

int checker_teker(int negativ_count, const char *str, long v)
{
    for (int i = 0; str[i] < 48 || str[i] >= 58; i++) {
        if (str[i] == '-') {
            negativ_count++;
        }
    }
    if (negativ_count % 2 == 1 && negativ_count != 0) {
        v = -1 * v;
    }
    if (v == -2147483648) {
        return (v);
    }
    else if (v == 2147483648) {
        return (0);
    }
    return (v);
}

int my_getnbr(char const *str)
{
    int negativ_count = 0;
    int cpt_nbr = 0;
    long var_out = 0;

    while (str[cpt_nbr] != '\0') {
        if (str[cpt_nbr] >= 48 && str[cpt_nbr] < 58) {
            var_out = 10 * var_out + (str[cpt_nbr] - 48);
        }
        else if (str[cpt_nbr] >= 65 && str[cpt_nbr] < 123) {
            return (var_out);
        }
        if (var_out > 2147483648 || var_out < -2147483648) {
            return (0);
        }
        cpt_nbr++;
    }
    return (checker_teker(negativ_count, str, var_out));
}
