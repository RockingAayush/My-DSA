#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);

        for(int j = 0; j < m-1; j++){
            for(int i = 1; i < n; i++){
                dp[i] += dp[i-1];
            } 
        }

        return dp[n-1];
    }
};

int main() {
    Solution sol;
    
    // Test case 1: 3x7 grid
    int result1 = sol.uniquePaths(3, 7);
    cout << "Test case 1: m=3, n=7" << endl;
    cout << "Unique paths: " << result1 << endl;
    cout << "Expected: 28" << endl << endl;
    
    // Test case 2: 3x3 grid
    int result2 = sol.uniquePaths(3, 3);
    cout << "Test case 2: m=3, n=3" << endl;
    cout << "Unique paths: " << result2 << endl;
    cout << "Expected: 6" << endl << endl;
    
    // Test case 3: 1x1 grid
    int result3 = sol.uniquePaths(1, 1);
    cout << "Test case 3: m=1, n=1" << endl;
    cout << "Unique paths: " << result3 << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 4: 2x2 grid
    int result4 = sol.uniquePaths(2, 2);
    cout << "Test case 4: m=2, n=2" << endl;
    cout << "Unique paths: " << result4 << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 5: 1x10 grid
    int result5 = sol.uniquePaths(1, 10);
    cout << "Test case 5: m=1, n=10" << endl;
    cout << "Unique paths: " << result5 << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}