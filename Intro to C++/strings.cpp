#include <iostream>
#include <string>

using namespace std;

int main(){

    string mystring = "Alpha";
    string name;
    cout << "Enter your name: ";
    cin >> name;
    
    cout << name << " is " << mystring;
    return 0;
}