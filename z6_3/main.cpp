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
        wcout << L"Using standard file ";
        cout << def << endl;
    }
    return file;
}

void nd(string file1, string file2, string out)
{
    wcout << L"Files ";
    cout << file1;
    wcout << L" and ";
    cout << file2;
    wcout << L" merged in file ";
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
    wcout << L"Merge two files in one huge file.\n";


    file1 = inFile(L"Enter the name of the first file, either \".\" for standard\n", file1_d);
    file2 = inFile(L"Enter the name of the second file, either \".\" for standard\n", file2_d);
    out = inFile(L"Enter the name output file, either \".\" for standard\n", out_d);


    read_n_write(file1, out);
    read_n_write_end(file2, out);

    nd(file1, file2, out);
    cout << endl;

    system("pause");
    return 0;

}





