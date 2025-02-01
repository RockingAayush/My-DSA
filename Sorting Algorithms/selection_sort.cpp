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

//Time Complexity: O(N^2)
//Space Complexity: O(1) only extra variable is the swap temp variable
void selection_sort(vector<int> &v){
    for (int i = 0; i < v.size(); i++)     //Iterates through each element
    {
        int min_index = i;          //Assume the current element is the minimum element
        for (int j = i + 1; j < v.size(); j++){         //Iterate through the remaining array
            //Check if any other element is less than the current element in the rest array 
            if (v[j] < v[min_index]){
                min_index = j;
            }
        }
        swap(v,i, min_index);      //Swap elements
    }
    
}

int main(){
    vector<int> vec1;
    vec1 = {2,1,4,6,4,5};
    
    cout << "Original Array: ";
    display(vec1);

    selection_sort(vec1);
    
    cout << "Sorted Array: ";
    display(vec1);
    return 0;
}