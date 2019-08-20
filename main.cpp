#include "my_functions.hpp"
#include "unit_tests.hpp"
#include <algorithm>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    setlocale(LC_ALL, "Russian");

    string  file_name_and_adress = "D:\\test.txt";      // PUT YOUR FILE HERE
    string  file_copy            = "D:\\test_copy.txt"; // YOUR RESULT
    wstring word_to_remove = L"слово"; // PUT YOUR WORD TO REMOVE HERE

    vector<wstring> vec_for_line;
    wstring         string_from_file;

    wifstream file_to_read(file_name_and_adress);
    if (!file_to_read)
    {
        cerr << "can't open file " << file_name_and_adress << "\n";
        return 1;
    }

    wofstream file_to_write(file_copy);
    if (!file_to_write)
    {
        cerr << "can't open file " << file_copy << "\n";
        return 1;
    }

    while (getline(file_to_read, string_from_file))
    {
        string_tolower(string_from_file);
        string_tolower(word_to_remove);

        wcout << string_from_file << endl;

        line_to_vector(vec_for_line, string_from_file, word_to_remove);

        sort(string_from_file.begin(), string_from_file.end());
        wcout << string_from_file << endl;

        vector_to_file(vec_for_line, file_to_write);
    }

    file_to_read.close();
    file_to_write.close();

    return RUN_ALL_TESTS();
}
