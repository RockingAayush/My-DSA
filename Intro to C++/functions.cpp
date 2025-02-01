#include <iostream>
using namespace std;

int power(int a,int b){
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int even_check(int num){
    if (num%2 == 0){
        return true;
    }
    else
    {
        return false;
    }
}

int factorial(int num){
    if(num == 0 or num == 1){
        return 1;
    }
    return factorial(num - 1) * num; 
}

int nCr(int n, int r){
    return (factorial(n)/(factorial(n-r)*factorial(r)));
}

int main(){
    int a ,b;
    cout << "Enter two numbers:";
    cin >> a >> b;

    //cout << power(a,b) << endl;
    //cout << even_check(a) << endl;
    //cout << even_check(b) << endl;
    cout << factorial(a) << "  " << factorial(b) << endl;
    cout << nCr(a,b);
    return 0;
}

