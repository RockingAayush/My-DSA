#include<iostream>
using namespace std;

int main() {
    int a = 123;
    cout << a << endl;

    char b = 'c';
    cout << b << endl;

    double c = 12.3;
    cout << c << endl;

    int size = sizeof(c);
    cout << "Size of double:" << size << endl;

    // Typecasting
    unsigned int d = 'b';   // Converts to ascii
    char e = 99;            // Converts from ascii
    cout << d << endl
         << e << endl;
}