/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/

#include <criterion/criterion.h>
#include "my.h"
#include "bistromatic.h"
#include <string.h>

Test(mul, mul_zeros)
{
    char a[] = "0";
    char b[] = "0";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    if (res == NULL){
        res = my_strdup("!");
    }
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "0");
}

Test(mul, mul_zero_and_number)
{
    char a[] = "3";
    char b[] = "0";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    if (res == NULL){
        res = my_strdup("!");
    }
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "0");
}

Test(mul, mul_small_numbers)
{
    char a[] = "4";
    char b[] = "2";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  8");
    free(res);
}

Test(mul, mul_big_numbers)
{
    char a[] = "17465765";
    char b[] = "654358";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  11428863053870");
    free(res);
}

Test(mul, mul_large_numbers)
{
    char a[] = "234567897654654678654";
    char b[] = "6543567865435678976548976546789";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res,
    "  1534910957355803524493640880181591675863735390542006");
    free(res);
}

Test(mul, mul_negative_numbers)
{
    char a[] = "{600";
    char b[] = "{700";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  420000");
    free(res);
}

Test(mul, mul_positive_and_negative_numbers1)
{
    char a[] = "{600";
    char b[] = "700";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{  420000");
    free(res);
}

Test(mul, mul_positive_and_negative_numbers2)
{
    char a[] = "600";
    char b[] = "{700";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = mul(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{  420000");
    free(res);
}
