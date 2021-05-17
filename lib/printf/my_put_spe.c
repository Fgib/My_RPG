/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_put_spe
*/

void pchar(char c);
int pstr(char *str);
void phexa(int dec_nbr);

void put_spe(char truc)
{
    if (truc > 126) {
        pchar('\\');
        phexa((int)truc);
    }
    else if (truc > 7 && truc < 32) {
        pchar('\\');
        pchar('0');
        phexa(truc);
    } else {
        pchar('\\');
        pchar('0');
        pchar('0');
        phexa((int)truc);
    }
}

void pspe(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 31 && str[i] < 127) {
            pchar(str[i]);
        } else {
            put_spe(str[i]);
        }
    }
}
