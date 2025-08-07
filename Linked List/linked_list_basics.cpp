#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // Constructor
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    // Linked list are used because arrays are of fixed size and continuous
    // Easier to increase or decrease the size of a linked list and it is also not continuous
    vector<int> arr = {1,2,3,4,5};
    Node* y = new Node(arr[0],nullptr);

    cout << y;   // Gives address of the element
    cout << y->data;  // Gives 'data' that is in the node 
    return 0;
}