#include<iostream>
#include<vector>
using namespace std;


void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void recursive_insertion_sort(vector<int> &v, int i, int n){
    if (i == n)
    {
        return;
    }
    int j = i;
    while (j > 0 && v[j-1] > v[j])
    {
        int temp = v[j-1];
        v[j-1] = v[j];
        v[j] = temp;
        j--;
    }
    recursive_insertion_sort(v,i+1,n);
    return;
}

int main(){
    vector<int> vec1;
    vec1 = {2,1,4,6,4,5};
    
    cout << "Original Array: ";
    display(vec1);

    recursive_insertion_sort(vec1,0,vec1.size());
    
    cout << "Sorted Array: ";
    display(vec1);
    return 0;
}