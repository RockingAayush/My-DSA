#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    // Constructors
    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* convertArraytoDLL(vector<int> &arr){
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
};

void print(Node* head){
    Node* temp = head;
    while (head != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
};

Node* deleteHead(Node* head){
    if((head == nullptr) or (head->next == nullptr)){
        return nullptr;
    }
    else{
        Node* temp = head;
        head = head->next;
        head->back = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }

};

int main(){
    vector<int> arr = {2,5,6,7,2};
    Node* head = convertArraytoDLL(arr);
    
    head = deleteHead(head);
    print(head);
    return 0;
};