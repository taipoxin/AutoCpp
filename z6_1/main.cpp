#include <iostream>
#include <locale>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;



vector<string> read(string fileName)
{
    vector<string> collection;
    ifstream file(fileName);
    while (file)
    {
        string str;
        getline(file, str);
        // add to vector
        collection.push_back(str);
    }
    return collection;
}

void copy(string from, string to)
{
    vector<string> coll1 = read(from);
    vector<string> coll2 = read(to);

    ofstream fout(to, ios_base::out);
    int i = 1;
    for (const string &str : coll2)
    {
    string s = to_string(i) + " " + str;
    fout << s << endl;
    i++;
    }
    for (const string &str : coll1)
    {
    string s = to_string(i) + " " + str;
    fout << s << endl;
    i++;
    }
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

void nd(string file1, string file2)
{
    wcout << L"File ";
    cout << file1;
    wcout << L" is copied to ";
    cout << file2;
    wcout << L" with the addition of line numbers.";
    cout << endl;
}

int main()
{
    string file1_d = "file1.txt";
    string file2_d = "file2.txt";

    string file1;
    string file2;

    setlocale(LC_ALL, "Russian");


    wcout << L"Copy one file to the second and add line numbers\n";


    file1 = inFile(L"Enter the name of the first file, either press \".\" for standard\n", file1_d);
    file2 = inFile(L"Enter the name of the first file, either press \".\" for standard\n", file2_d);

    copy(file1, file2);

    cout << endl;

    vector<string> s = read(file2);
    copy(s.begin(),
              s.end(),
              ostream_iterator<string>(cout, "\n"));

    cout << endl;

    nd(file1, file2);


    system("pause");
    return 0;

}





