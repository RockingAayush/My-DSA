#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // pre-compute
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    
    // iterating the map
    // for (auto it: mpp)
    // {
    //     cout << it.first << "-->" << it.second << endl;
    // }
    

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    
    // Storing and fetching is O(Log N) Time complexity
    // In unordered map storing and fetching average and best case is O(1) and the worst case is O(n)
    // Collision - Division Method results in O(n)
    return 0;
}