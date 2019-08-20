#pragma once
#include "my_functions.hpp"
#include <gtest/gtest.h>

#include <numeric>

TEST(string_tolower, PositiveNos)
{
    wstring test_str1_input = L"ThiS is TEST StrING №1 !!";
    wstring test_str2_input = L"ЭТо тестоВАя СтРоКа №2 !!";
    wstring test_str3_input =
        L"ThiS is ЭТо TEST тестоВАя StrING42_СтРоКа №3 !!";

    string_tolower(test_str1_input);
    string_tolower(test_str2_input);
    string_tolower(test_str3_input);

    EXPECT_EQ(L"this is test string №1 !!", test_str1_input);
    EXPECT_EQ(L"это тестовая строка №2 !!", test_str2_input);
    EXPECT_EQ(L"this is это test тестовая string42_строка №3 !!",
              test_str3_input);
}

// check what the function "line_to_vector" ...
//... DOES NOT write the given word to the vector
TEST(line_to_vector, PositiveNos)
{
    vector<wstring> test_vector1, test_vector2, test_vector3;

    wstring test_str1_input =
        L"   ThiS    is TEST StrING with the Word to   erase !!   ";
    wstring test_word_to_erase1 = L"Word";
    wstring test_str1_result    = L"ThiSisTESTStrINGwiththetoerase!!";
    wstring test_str1_output;

    wstring test_str2_input =
        L"  Это тестовая    строка со,!& словом 668 для удаления !!";
    wstring test_word_to_erase2 = L"словом";
    wstring test_str2_result = L"Этотестоваястрокасо,!&668дляудаления!!";
    wstring test_str2_output;

    wstring test_str3_input =
        L"Это тестовая string, со wordсловом для удаления !!";
    wstring test_word_to_erase3 = L"wordсловом";
    wstring test_str3_result = L"Этотестоваяstring,содляудаления!!";
    wstring test_str3_output;

    line_to_vector(test_vector1, test_str1_input, test_word_to_erase1);
    line_to_vector(test_vector2, test_str2_input, test_word_to_erase2);
    line_to_vector(test_vector3, test_str3_input, test_word_to_erase3);

    test_str1_output =
        accumulate(test_vector1.begin(), test_vector1.end(), wstring());

    test_str2_output =
        accumulate(test_vector2.begin(), test_vector2.end(), wstring());

    test_str3_output =
        accumulate(test_vector3.begin(), test_vector3.end(), wstring());

    EXPECT_EQ(test_str1_result, test_str1_output);
    EXPECT_EQ(test_str2_result, test_str2_output);
    EXPECT_EQ(test_str3_result, test_str3_output);
}
