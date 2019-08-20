#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void string_tolower(wstring& str);

void line_to_vector(vector<wstring>& vec, wstring& buf_string,
                    wstring& word_to_delete);

void vector_to_file(vector<wstring>& vec, wofstream& file);
