#include <iostream>
using namespace std;

/*
int main(){
    int myinteger = 5;
    int *ptr;

    ptr = &myinteger;
    cout << "Address: " << ptr << endl;
    cout << "Value: " << *ptr;
    return 0;
}
*/

/*
int main(){
    int i = 5;
    int *ptr = &i;

    cout << ptr++ << endl << ptr;
    return 0;
}
*/

/*
int main(){
    int x = 8;
      int *       p1 = &x;  // non-const pointer to non-const int
const int *       p2 = &x;  // non-const pointer to const int
      int * const p3 = &x;  // const pointer to non-const int
const int * const p4 = &x;  // const pointer to const int

    *p2 = 5;  // Error as p2 value is const
    p2 = p2 + 1;  // Works as pointer itself is non const

    p4 = p4 + 1;  // p2 itself is const
    return 0;
}
*/

/*
int main(){
    const char * mystring = "macaroni";
    cout << *(mystring) << endl;     // Accessing the first element
    cout << *(mystring + 3);   //Accessing the 4th element
    return 0;
}
*/

int increase(void *data, int psize){
    if (psize == sizeof(char))      //check if input is char
    {
        char * pchar;         // Initialize pchar of *char type
        pchar = (char *)data;   // Assigning pchar data ,also see we have to type cast void type 
        ++(*pchar);
    }
    
    else if (psize == sizeof(int))
    {
        int * pint;
        pint = (int *)data;
        ++(*pint);
    }
    return 0;
}

int main(){
    int i = 5;
    char h = 'j';

    int *ptr1 = &i;
    char *ptr2 = &h;
    increase(ptr1,sizeof(i));
    increase(ptr2,sizeof(h));

    cout << i << h;
    return 0;
}