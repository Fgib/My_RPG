/*
** EPITECH PROJECT, 2020
** B-PSU-100-LYN-1-1-myprintf-florian.gibault
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void pchar(char c);
int pnbr(int nb);
int pstr(char *str);
int poct(int dec_nbr);
void phexm(int dec_nbr);
void phexa(int dec_nbr);
void pbin(int nbr);
void pptr(int value);
void pspe(char *str);
char *stad(char *str1, char *str2);
char *gstr(int val);
char *cts(char c);

void my_printf(char *str, ...)
{
    va_list list;
    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            str[i + 1] == 'u' ? pnbr(va_arg(list, unsigned int)) : 0;
            str[i + 1] == 'c' ? pchar((char) va_arg(list, int)) : 0;
            str[i + 1] == 's' ? pstr(va_arg(list, char *)) : 0;
            str[i + 1] == 'X' ? phexm(va_arg(list, int)) : 0;
            str[i + 1] == 'x' ? phexa(va_arg(list, int)) : 0;
            str[i + 1] == 'b' ? pbin(va_arg(list, int)) : 0;
            str[i + 1] == 'd' ? pnbr(va_arg(list, int)) : 0;
            str[i + 1] == 'i' ? pnbr(va_arg(list, int)) : 0;
            str[i + 1] == 'o' ? poct(va_arg(list, int)) : 0;
            str[i + 1] == 'p' ? pptr(va_arg(list, int)) : 0;
            str[i + 1] == '%' ? pchar('%') : 0;
            *str++;
        } else
            pchar(str[i]);
    }
    va_end(list);
}

char *my_sprintf(char *str, ...)
{
    va_list list;
    char *var = malloc(sizeof(char));

    var[0] = '\0';
    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            str[i + 1] == 'c' ? var = stad(var,
        cts((char)va_arg(list, int))) : 0;
            str[i + 1] == 's' ? var = stad(var, va_arg(list, char *)) : 0;
            str[i + 1] == 'd' ? var = stad(var, gstr(va_arg(list, int))) : 0;
            str[i + 1] == 'i' ? var = stad(var, gstr(va_arg(list, int))) : 0;
            str[i + 1] == '%' ? var = stad(var, "%") : 0;
            *str++;
        } else
            var = stad(var, cts(str[i]));
    }
    va_end(list);
    return var;
}