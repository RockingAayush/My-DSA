#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }  
    cout << endl;  
}

void siftUp(vector <int> &arr){
    int i = arr.size() - 1;
    while(i>0){
        int parent = (i - 1)/2;
        if(arr[i] < arr[parent]){
            swap(arr[i],arr[parent]);
            i = parent;
        }
        else{
            break;
        }
    } 
}

void siftDown(vector<int> &arr, int i){
    int n = arr.size();
    while (true){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < n && arr[left] < arr[smallest]){
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest]){
            smallest = right;
        }
        
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            i = smallest;
        } else break;

    }    
}

vector<int> makeMinHeap(vector<int> arr){
    int n = arr.size();

    for (int i = (n/2)-1; i >= 0; i--){
        siftDown(arr,i);    
    }
    return arr;
}

int main(){
    vector<int> arr = {1,2,3,4,5,1};
    print(arr);
    vector<int> minHeap = makeMinHeap(arr);
    print(minHeap);
    return 0;
}