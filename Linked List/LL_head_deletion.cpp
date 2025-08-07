#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
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

Node* deleteHead(Node* head){

    if (head==NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArraytoLL(arr);
   
    head = deleteHead(head);
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}