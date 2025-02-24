#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void swap(vector<int> &v,int index1,int index2){
    int temp = v[index1];
    v[index1] = v[index2];
    v[index2] = temp; 
}

int recursive_bubble_sort(vector<int> &v ,int n){
    if(n==1){
        return 0;
    }

    int smallest_element;
    for (size_t i = 0; i <= n - 2; i++)
    {
        if (v[i] > v[i + 1]) {
            int temp = v[i + 1];
            v[i + 1] = v[i];
            v[i] = temp;
        }
    }
    recursive_bubble_sort(v,n-1);
    return 0;
}


int main(){
    vector<int> vec1;
    vec1 = { 64, 34, 25, 12, 22, 11, 90 };
    
    cout << "Original Array: ";
    display(vec1);

    recursive_bubble_sort(vec1,vec1.size());
    
    cout << "Sorted Array: ";
    display(vec1);
    return 0;
}