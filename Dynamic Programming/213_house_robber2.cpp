#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n);
        if(n == 1){
            return nums[0];
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> sv1(nums.begin()+1,nums.end());
        vector<int> sv2(nums.begin(),nums.end()-1);

        return max(solve(sv1),solve(sv2));
    }
};

int main() {
    Solution sol;
    
    // Test case 1: [1,2,3,1]
    vector<int> test1 = {1, 2, 3, 1};
    int result1 = sol.rob(test1);
    cout << "Test case 1: [1,2,3,1]" << endl;
    cout << "Max money robbed: " << result1 << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test case 2: [2,3,2]
    vector<int> test2 = {2, 3, 2};
    int result2 = sol.rob(test2);
    cout << "Test case 2: [2,3,2]" << endl;
    cout << "Max money robbed: " << result2 << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test case 3: [5,3,4,11,2]
    vector<int> test3 = {5, 3, 4, 11, 2};
    int result3 = sol.rob(test3);
    cout << "Test case 3: [5,3,4,11,2]" << endl;
    cout << "Max money robbed: " << result3 << endl;
    cout << "Expected: 16" << endl << endl;
    
    // Test case 4: [1]
    vector<int> test4 = {1};
    int result4 = sol.rob(test4);
    cout << "Test case 4: [1]" << endl;
    cout << "Max money robbed: " << result4 << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 5: [2,1]
    vector<int> test5 = {2, 1};
    int result5 = sol.rob(test5);
    cout << "Test case 5: [2,1]" << endl;
    cout << "Max money robbed: " << result5 << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}