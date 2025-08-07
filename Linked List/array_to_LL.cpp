#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // Constructors
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArraytoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int LengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;

    while (temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    vector<int> arr = {2,5,6,7,2};
    Node* head = convertArraytoLL(arr);
    Node* temp = head;

    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl << LengthOfLL(head) ;
    return 0;
}