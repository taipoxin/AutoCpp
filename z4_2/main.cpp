#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;


string checkString(string input)
{
    istringstream buf(input);
    istream_iterator<string> beg(buf), end;

    vector<string> tokens(beg, end); // done!

    string result = "";
    string prev = "";
    for(auto& s: tokens) {
        if (s != prev) {
            result.append(s);
            result.append(" ");
        }
        prev = s;
    }
    return result;
}

int main() {
    cout << "Clears twice recorded words in the text.\n";
    cout << "Please write text of enter \".\" for use existed pattern\n";
    string input = "";
    string pattern = "How old are are you?\n";
    getline ( cin, input ); //заполняем строку

    if (input == ".") {
        cout << "Using pattern: ";
        cout << pattern;
        input = pattern;
    }

    string result = checkString(input);

    cout << "Result text:\n";
    cout << result << endl;

    system("pause");

    return 0;
}