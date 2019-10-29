/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Div and mod
*/

#include "my.h"
#include "bistromatic.h"

int is_nb_pos(int *val, char **a_n_save)
{
    if (my_strcmp(sub("!", a_n_save[0], val[0]), "!") != 0)
        if (a_n_save[0][0] != 123)
            return 1;
    return 0;
}

void sub_while_pos(int *val, char **a_n_save, char **res_n_add, char *b_with_z)
{
    while (is_nb_pos(val, a_n_save) == 1) {
        a_n_save[1] = my_strdup(a_n_save[0]);
        a_n_save[0] = infinadd_base(&a_n_save[0][val[1]], b_with_z, val[0]);
        if (is_nb_pos(val, a_n_save) == 1) {
            res_n_add[0] = infinadd_base(res_n_add[0], res_n_add[1], val[0]);
            val[1] = 2;
        } else if (my_strcmp(sub("!", a_n_save[0], val[0]), "!") == 0) {
            res_n_add[0] = infinadd_base(res_n_add[0], res_n_add[1], val[0]);
            break;
        } else
            break;
    }
}

char *make_div(char *a, int base, char *neg_b, int dif_lenght)
{
    char *a_save = "";
    char *add_result = "";
    char *b_with_zeros = "";
    int begin = 0;
    char *result = "!";
    int values[] = {base, begin};
    char *a_and_save[] = {a, a_save};
    char *res_and_add[] = {result, add_result};

    for (int i = dif_lenght; i >= 0; i--) {
        b_with_zeros = add_zeros(neg_b, b_with_zeros, i);
        res_and_add[1] = add_zeros("\"", res_and_add[1], i);
        sub_while_pos(values, a_and_save, res_and_add, b_with_zeros);
        a_and_save[0] = my_strdup(a_and_save[1]);
        b_with_zeros = NULL;
        res_and_add[1] = NULL;
    }
    return res_and_add[0];
}

char *divi(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result = "!";
    char *neg_result = NULL;
    int dif_lenght = my_strlen(a) - my_strlen(b);
    char *neg_b = NULL;

    if (a[0] == 33) {
        result = malloc(sizeof(char) * 2);
        result = "0";
        return result;
    }
    result_sign = get_result_sign(a, b, result_sign);
    neg_b = add_minus(b, neg_b);
    result = make_div(a, base, neg_b, dif_lenght);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}

char *mod(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result;
    char *neg_result = NULL;

    if (a[0] == 33) {
        result = malloc(sizeof(char) * 2);
        result = "0";
        return result;
    }
    if (a[0] == 123 && b[0] == 123)
        result_sign = -1;
    result_sign = get_result_sign(a, b, result_sign);
    result = sub(a, mul(divi(a, b, base), b, base), base);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}