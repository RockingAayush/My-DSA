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

Node* deleteTail(Node* head){

    if (head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = nullptr;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,3,5,6,7};
    Node* head = convertArraytoLL(arr);
   
    head = deleteTail(head);
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}