/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-florian.gibault
** File description:
** my_sort_in_array
*/

int checker_array(int *array, int size, int i)
{
    int temp_var;

    for (int j = 0; j < size; j++) {
        if (*(array + j) > *(array + i)) {
            temp_var = *(array + i);
            *(array + i) = *(array + j);
            *(array + j) = temp_var;
        }
    }
    return 0;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        checker_array(array, size, i);
    }
}