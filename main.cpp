#include <iostream>
#include "table.h"
#include <locale.h>
using namespace std;

bool isValid(const wstring& s) {
    for (wchar_t i:s) {
        if (!(iswalpha(i))) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "");
    wstring text = L"";
    wstring ciphertext = L"";
    unsigned int columns;
    unsigned int op;
    wcout << L"Введите количество столбцов: ";
    wcin >> columns;
    wcin.ignore(); // Игнорируем символ новой строки после считывания числа
    
    wcout << L"Ключ установлен\n";
    tableCipher cipher(columns);
    do {
        wcout << L"Введите номер операции (0-выход, 1-зашифровать, 2-расшифровать): ";
        wcin >> op;
        if (op > 2) {wcout << L"Неверный номер операции\n";}
        else if (op == 1) {
            wcout << L"Введите текст: ";
            wcin.ignore();
            getline(wcin, text);
            wstring ciphertext = cipher.encrypt(text);
            wcout << L"Зашифрованный текст: " << ciphertext << endl;
        }
        else if (op == 2) {
            wcout << L"Введите зашифрованный текст: ";
            wcin.ignore();
            getline(wcin, ciphertext);
            wstring decryptedText = cipher.decrypt(ciphertext);
            wcout << L"Расшифрованный текст: " << decryptedText << endl;
        }
    } while (op != 0);
    return 0;
}
