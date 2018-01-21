#include <iostream>
#include <locale>
#include <fstream>

using namespace std;


void read_n_write_end(string fileName, string out)
{
    ifstream file(fileName);
    ofstream fout(out, ios_base::app);
    while(file)
    {
        string str;
        getline(file, str);
        fout << str << endl;
    };
    fout.close();
}

void read_n_write(string fileName, string out)
{
    ifstream file(fileName);
    ofstream fout(out, ios_base::out);
    while(file)
    {
        string str;
        getline(file, str);
        fout << str << endl;
    };
    fout.close();
 }

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

void nd(string file1, string file2, string out)
{
    wcout << L"Файлы ";
    cout << file1;
    wcout << L" и ";
    cout << file2;
    wcout << L" объединены в большом файле ";
    cout << out << endl;
}

int main()
{
    string file1_d = "file1.txt";
    string file2_d = "file2.txt";
    string out_d = "output.txt";

    string file1;
    string file2;
    string out;

    setlocale(LC_ALL, "Russian");
    wcout << L"Объединить два файла в один большой\n";


    file1 = inFile(L"Введите название первого файла либо . для стандартного\n", file1_d);
    file2 = inFile(L"Введите название второго файла либо . для стандартного\n", file2_d);
    out = inFile(L"Введите название файла для объединения либо . для стандартного\n", out_d);


    read_n_write(file1, out);
    read_n_write_end(file2, out);

    nd(file1, file2, out);
    cout << endl;

    system("pause");
    return 0;

}





