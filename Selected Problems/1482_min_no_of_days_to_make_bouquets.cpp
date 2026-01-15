#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Greedy + Linear Search for cheching if at a given day we can make m bouquets
    bool checkIfBouquetPossible(vector<int>& bloomDay, int m, int k, int day){
        int num_of_bouquets = 0;
        int counter = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                counter++;
            }

            if(counter >= k){
                num_of_bouquets++;
                counter = 0;
            }

            if(bloomDay[i] > day){
                counter = 0;
            }
        }
        return num_of_bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)k * m > bloomDay.size()) return -1;

        int low = bloomDay[0], high = bloomDay[0];
        for(int i = 0; i < bloomDay.size(); i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        // Binary Search on days possible
        while(low < high){
            int mid = low + (high - low) / 2;
            if(checkIfBouquetPossible(bloomDay, m, k, mid)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;

    // -------- Test Case 1 --------
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    cout << "Test Case 1 Output: "
         << sol.minDays(bloomDay1, m1, k1) << endl;
    // Expected: 3

    // -------- Test Case 2 --------
    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    cout << "Test Case 2 Output: "
         << sol.minDays(bloomDay2, m2, k2) << endl;
    // Expected: -1 (not enough flowers)

    // -------- Test Case 3 --------
    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    int m3 = 2, k3 = 3;
    cout << "Test Case 3 Output: "
         << sol.minDays(bloomDay3, m3, k3) << endl;
    // Expected: 12

    return 0;
}
