#include <iostream>
#include <math.h>

using namespace std;


int main()
{
    int dec;
    int bit;
    int quotient;
    string bitstring;

    cin >> dec;
    while (dec > 0 )
    {
        bit      = dec % 2 ;
        quotient = dec / 2 ;
        bitstring = to_string(bit) + bitstring;
        dec = quotient;
    }

    cout <<bitstring<< endl;
    system("pause");
    return 0;
}

/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    int dec;
    std::cin >> dec;
    return 0;
}
 */




