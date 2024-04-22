#include <iostream>
#include <string>
#include <fstream>


using namespace std;
bool isIdentifier(string text) {
    // Проверка первого символа
    if (!(text[0] == '_' || (text[0] >= 'a' && text[0] <= 'z') || (text[0] >= 'A' && text[0] <= 'Z'))) {
        return false;
    }

    // Проверка остальных символов
    for (int i = 1; text[i] != '\0'; i++) {
        if (!(text[i] == '_' || (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= '0' && text[i] <= '9'))) {
            return false;
        }
    }

    return true;
}

bool isInteger(string text) {
    // Проверка первого символа или знака минуса
    if (!(text[0] == '-' || text[0] == '+' || (text[0] >= '0' && text[0] <= '9'))) {
        return false;
    }

    // Проверка остальных символов
    for (int i = 1; text[i] != '\0'; i++) {
        if (!(text[i] >= '0' && text[i] <= '9')) {
            return false;
        }
    }

    return true;
}

void read_file(fstream& file, string text, int& bit) {
    string word;
    file.seekg(0);
    while (file >> word) {
        if (word == text) {
            bit = 0;
            return;
        }
        else { 
        bit = 1; 
        }
    }
}




int main() {
    setlocale(LC_ALL, "RU");
    int bit = 1;
    string text;
    cout << "Введите текст: ";
    cin >> text;
   

    fstream outfile;
    outfile.open("word.txt", ios::in | ios::out | ios::app);
    if (!outfile.is_open()) {
        cout << "Ошибка прочтения файла";
        return 1;
    }

    read_file(outfile, text, bit);
    if (bit == 0) {
        cout << "Это слово является ключевым!!!";
    }

    if (bit == 1) {
        if (isIdentifier(text)) {
            cout << "Текст является идентификатором." << endl;
        }
        else if (isInteger(text)) {
            cout << "Текст является записью целого числа." << endl;
        }
        else {
            cout << "Текст не является идентификатором или записью целого числа." << endl;
        }
    }

    return 0;
}
