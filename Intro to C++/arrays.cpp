#include <iostream>
using namespace std;
/*
int main(){
    int a[5] = {4,5,6,7123,4};  // Declaration with instantiation

    a[3] = a[2] + a[1];

    a[9] = 1000;  // Changing out of bounds value
    
    for(int i = 0; i<10; i++){
        cout << a[i] << endl;
    }
    
    
    return 0;
}
*/
/*
int main(){
    float a[5] = {12,23,12,12,12};
    float sum = 0;

    for(int i = 0; i<5;i++){
        sum += a[i];
    }

    cout << sum;

}
*/

void add_2_to_each_element(int arg[], int length){
    for (int i = 0; i < length; i++)
    {
        arg[i] += 2;
    }
    return ;
}

int main(){
    int a[6] = {1,2,3,4,5,6};
    add_2_to_each_element(a,6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}