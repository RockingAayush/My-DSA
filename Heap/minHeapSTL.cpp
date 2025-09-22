#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // priority_queue<int> pq; Max Heap by default
    priority_queue<int , vector<int>, greater<int>> pq; // Min Heap 
    pq.push(20);
    pq.push(10);
    pq.push(30);
    pq.push(10);
    pq.push(20);

    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}