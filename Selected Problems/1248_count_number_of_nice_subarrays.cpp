#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int atmost(vector<int>& nums, int k){
        int count = 0;
        int numOdd = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] % 2 != 0){
                    numOdd++;
            }
            while(numOdd > k){
                if(nums[left] % 2 != 0){
                    numOdd--;
                }
                left++;
            }
            // Now all subarrays ending at right with atmost k odd numbers
            count += right - left + 1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1); // Exactly k = atmost k - atmost (k-1) remember this
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl; // Output: 2
    vector<int> nums2 = {2,4,6};
    int k2 = 1;
    cout << sol.numberOfSubarrays(nums2, k2) << endl; // Output: 0
    vector<int> nums3 = {2,2,2,1,2,2,1,2,2,2};
    int k3 = 2;
    cout << sol.numberOfSubarrays(nums3, k3) << endl; // Output: 16
    return 0;
}