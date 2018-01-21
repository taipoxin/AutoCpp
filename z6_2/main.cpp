#include <iostream>
#include <fstream>

using namespace std;


string inFile(const wchar_t* intro, string def)
{
    wcout << intro;
    string file;
    cin >> file;
    if (file == ".") {
        file = def;
        wcout << L"Использование стандартного файла ";
        cout << def << endl;
    }
    return file;
}

void showFile(const char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    string full = "";
    char cch;
    while ((cch = fgetc (file)) != EOF) {
        full += cch;
    }
    wcout << L"Исходный текст файла:\n\n";
    cout << full << endl << endl;
}

string parseFile(const char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    string full = "";
    char cch;
    while ((cch = fgetc (file)) != EOF) {
        // check number
        int ch  = cch - '0';
        if (ch >= 0 && ch <= 9) {
            string c = "";
            for (int i = 0; i < ch; i++) {
                if (ch % 2 == 0) {
                    c = c + "+";
                }
                else {
                    c = c + "-";
                }
            }
            // запись с
            full += c;
        }
        else {
            full += cch;
        }
    }
    return full;
}

void write(string what, string file)
{
    ofstream fout(file, ios_base::out);
    fout << what;
    fout.close();
}

int main() {

    setlocale(LC_ALL, "Russian");

    string file1_d = "text.txt";
    string file1;


    wcout << L"Заменить в файле каждую цифру на последовательность\n";
    wcout << L"знаков + (для четных) и - (для нечетных), длина \n";
    wcout << L"последовательности соответствует значению цифры\n\n";


    file1 = inFile(L"Введите название файла либо . для стандартного\n", file1_d);
    const char *file1_c = file1.c_str();
    showFile(file1_c);
    string text = parseFile(file1_c);
    wcout << L"Преобразованный текст файла:\n\n";
    cout << text << endl;
    write(text, file1);

    cout << endl;
    system("pause");
    return 0;


}