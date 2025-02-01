#include<iostream>
using namespace std;

int main() {
    
    long long unsigned int sum = 0;
    int a;
    cin >> a;

    for(long long unsigned int i=0;i<a;i++){
        sum = sum + i;
    }
    cout << sum;
}