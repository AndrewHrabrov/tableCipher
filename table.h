#pragma once
#include <string>
#include <vector>

class tableCipher {
public:
    tableCipher(unsigned int columns); // Конструктор
    std::wstring encrypt(const std::wstring& sourcetext); 
    std::wstring decrypt(const std::wstring& ciphertext); 

private:
    unsigned int columns; 
};