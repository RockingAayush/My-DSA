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

void bubble_sort(vector<int> &v){
    int n = v.size();
    bool swapped;

    for (int i = 0; i < n-1; i++){ 
        swapped = false; 
        for (int j = 0; j < n - i - 1; j++){
            if (v[j] > v[j+1])
        {
            swap(v,j,j+1);
            swapped = true;
        }

        }
        if (!swapped)
            break;
    }
    
}

int main(){
    vector<int> vec1;
    vec1 = { 64, 34, 25, 12, 22, 11, 90 };
    
    cout << "Original Array: ";
    display(vec1);

    bubble_sort(vec1);
    
    cout << "Sorted Array: ";
    display(vec1);
    return 0;
}