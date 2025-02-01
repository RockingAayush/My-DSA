#include<iostream>
using namespace std;

int main() {
    int a;
    int b;

    cin >> a;
    cin >> b;

    if (a>b){
        cout << a << endl;
    }
    else if(a==0 && b==0){
        cout << 0 << endl;
    }
    else{
        cout << b << endl;
    }
    
    
}