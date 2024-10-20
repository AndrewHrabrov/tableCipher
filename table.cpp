#include "table.h"
#include <iostream>
#include <algorithm>

tableCipher::tableCipher(unsigned int columns) : columns(columns) {}

std::wstring tableCipher::encrypt(const std::wstring& sourcetext) {
    unsigned int rows = (sourcetext.length() + columns - 1) / columns; 
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(columns, ' ')); 

    for (size_t i = 0; i < sourcetext.length(); ++i) {
        table[i / columns][i % columns] = sourcetext[i];
    }
    
    std::wstring ciphertext;

    for (int column = columns - 1; column >= 0; --column) {
        for (unsigned int row = 0; row < rows; ++row) {
            ciphertext += table[row][column];
        }
    }
    return ciphertext;
}

std::wstring tableCipher::decrypt(const std::wstring& ciphertext) {
    unsigned int rows = (ciphertext.length() + columns - 1) / columns; 
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(columns, ' ')); 

    size_t i = 0;
    for (int column = columns - 1; column >= 0; --column) {
        for (unsigned int row = 0; row < rows; ++row) {
            if (i < ciphertext.length()) {
                table[row][column] = ciphertext[i++];
            }
        }
    }
    std::wstring sourcetext;
    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < columns; ++column) {
            sourcetext += table[row][column];
        }
    }
    

    return sourcetext;
}