#include<iostream>
using namespace std;

/*
int main() {
    int n ;
    cin >> n ;

    int i = 1;
    int start = 'A';
    while (i<=n){
        int j = 1;
        while (j<=n){
            cout << (char)(start + i - 1);
            j = j + 1;
        }   
        i=i+1;
        cout << endl;
    }   
}
*/

/*
int main() {
    int n;
    cin >> n;

    int i = 1;
    int start = 'A';
    while (i<=n)
    {
        int j = 1;
        while (j<=n)
        {
            cout << (char)(start + j - 1);
            j = j + 1;
        }
        start = start + 1;
        i = i + 1;
        cout << endl;
    }
    
}
*/
/*
int main() {
    int n;
    cin >> n;

    int i = 1;
    while (i<=n)
    {
        int j = 1;
        while (j<=n)
        {
            if (j > n - i){
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            
            j = j + 1; 
        }
        
        i = i + 1;
        cout << endl;
    }
    
}
*/

/*
int main() {
    int n;
    cin >> n;

    int i = 1;
    while (i<=n)
    {
        int j = 1;
        while (j<=n)
        {
            if (j <= n - i + 1){
                cout << "*";
            }
            else{
                cout << " ";
            }
            j = j + 1;
        }
        
        cout << endl;
        i = i + 1;
    }
    
}
*/
/*
int main() {
    int n;
    cin >> n;

    int i = 1;
    while (i<=n)
    {
        int space = n - i;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }
        
        int j = 1;
        while (j<=i)
        {
            cout << j;
            j = j + 1; 
        }
        
        int start = i-1;
        while (start)
        {
            cout << start;
            start = start - 1 ;
        }
        
        i = i + 1;
        cout << endl;
    }
    
}
*/

int main() {
    int n;
    cin >> n;

    int i = 1;
    while (i<=n)
    {
        int j = n - i + 1;
        while (j)
        {
            cout << n - i - j + 2;
            j = j - 1;
        }
        
        int k = i;
        while (k-1)
        {  
            cout << "*";
            k = k - 1;
        }
        
        int l = 1;
        while (l<i)
        {
            cout << "*";
            l = l + 1;
        }
        
        int p = n - i + 1;
        while (p)
        {
            cout << p;
            p = p - 1;
        }
        
        cout << endl;
        i = i + 1;
    }
    
}