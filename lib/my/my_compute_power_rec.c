/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    long var_out = nb;

    if (var_out > 2147483647 || p < 0 || p >= 31) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    else if (p == 1) {
        return (var_out);
    }
    else {
        var_out = var_out * my_compute_power_rec(var_out, p - 1);
    }
    return var_out;
}