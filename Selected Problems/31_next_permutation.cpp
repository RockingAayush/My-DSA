#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Lexicographically next permutation function (dictionary wise)
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first decreasing element from the end (pivot)
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If a pivot exists, find the smallest element greater than the pivot and swap them
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Reverse the elements after the pivot
    reverse(nums.begin() + i + 1, nums.end());
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 2, 1};
    nextPermutation(nums);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}