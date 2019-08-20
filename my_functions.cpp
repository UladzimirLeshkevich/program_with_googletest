#include "my_functions.hpp"

void string_tolower(wstring& str)
{
    auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
    f.tolower(&str[0], &str[0] + str.size());
}

void line_to_vector(vector<wstring>& vec, wstring& buf_string,
                    wstring& word_to_delete)
{
    wstring        tmp_string;
    wistringstream stream(buf_string);

    while (stream >> tmp_string)
    {
        if (tmp_string != word_to_delete)
            vec.push_back(tmp_string);
    }
}

void vector_to_file(vector<wstring>& vec, wofstream& file)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i != vec.size() - 1)
        {
            file << vec[i] + L" ";
        }
        else
        {
            file << vec[i];
        }
    }
    file << L"\n";
    vec.clear();
}
