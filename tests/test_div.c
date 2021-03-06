/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/

#include <criterion/criterion.h>
#include "bistromatic.h"
#include "my.h"

Test(div, div_zero_by_number)
{
    char a[] = "0";
    char b[] = "3";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    if (res == NULL){
        res = my_strdup("!");
    }
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "0");
}

Test(div, div_small_numbers)
{
    char a[] = "4";
    char b[] = "2";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  2");
    free(res);
}

Test(div, div_big_numbers)
{
    char a[] = "17465765";
    char b[] = "164358";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  106");
    free(res);
}

Test(div, div_big_numbers2)
{
    char a[] = "17465765";
    char b[] = "654358";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  26");
    free(res);
}

Test(div, div_large_numbers)
{
    char a[] = "234567892345678923456789";
    char b[] = "123456789123456789";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  1899999");
    free(res);
}

Test(div, div_negative_numbers)
{
    char a[] = "{700";
    char b[] = "{10";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  70");
    free(res);
}

Test(div, div_positive_and_negative_numbers1)
{
    char a[] = "{600";
    char b[] = "10";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{  60");
    free(res);
}

Test(div, div_positive_and_negative_numbers2)
{
    char a[] = "600";
    char b[] = "{10";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = divi(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{  60");
    free(res);
}
