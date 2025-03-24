#include<bits/stdc++.h>
using namespace std;

// Time complexity of O(Log N)
int binary_search(vector<int> vec , int target){
    int start = 0;
    int end = vec.size()-1;
    int mid;
    while (start<=end){
        mid = start + ((end - start)/2); // To avoid overflow cases 
        
        if(vec[mid] == target){
            return mid;
        }
        else if(vec[mid]>target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;    
}

int main(){
    vector<int> vec={3,4,6,7,9,12,16,17};
    cout << binary_search(vec,9);
    return 0;
}