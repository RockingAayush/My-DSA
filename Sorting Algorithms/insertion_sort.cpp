#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void insertion_sort(vector<int> &v){
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--; 
        }
        v[j + 1] = key;
        
    }
    
}

int main(){
    vector<int> vec1;
    vec1 = {2,1,4,6,4,5};
    
    cout << "Original Array: ";
    display(vec1);

    insertion_sort(vec1);
    
    cout << "Sorted Array: ";
    display(vec1);
    return 0;
}