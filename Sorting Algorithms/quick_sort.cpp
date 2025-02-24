#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int partition(vector<int> &v, int low, int high){
    int pivot = v[low];
    int i = low;
    int j = high;
    
    while (i < j)
    {
     while (v[i] <= pivot && i <= high -1)  // Finds the first element greater than the pivot
     {
        i++;
     }
     while (v[j] > pivot && j >= low + 1)   // Finds the first element smaller than the pivot
     {
        j--;
     }
     if (i < j)         // If they didnt cross swap the smaller and the greater element
     {
        swap(v[i],v[j]);
     }
     swap(v[low],v[j]);   // Finally put the pivot in its right position
        
    }
    return j; 
}

void quick_sort(vector<int> &v, int low, int high){
    if (low < high)
    {
        int pindex = partition(v,low,high);
        quick_sort(v,low,pindex-1);
        quick_sort(v,pindex+1,high);
    }
    
}

int main(){
    vector<int> vec1;
    vec1 = {2,1,4,6,4,5};
    
    cout << "Original Array: ";
    display(vec1);

    quick_sort(vec1,0,vec1.size()-1);
    
    cout << "Sorted Array: ";
    display(vec1);
    return 0;
}