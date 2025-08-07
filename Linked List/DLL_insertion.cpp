#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* back;
    Node* front;

    public:
    Node(int val1,Node* back1,Node* front1){
        val = val1;
        back = back1;
        front = front1;
    }
};

Node* convert_arr_to_DLL(vector<int> arr){
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* mover = head;

    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i],mover,nullptr);
        mover->front = temp;
        mover = temp;
    }

    return head;
}

void print(Node* head){
    Node* temp = head;
    while (head != nullptr){
        cout << temp->val << " ";
        temp = temp->front;
    }
};

Node* insertBeforeHead(int val,Node* head){
    Node* newHead = new Node(val,nullptr,head);
    head->back = newHead;
    return newHead;
}

Node* insertBeforeTail(int val,Node* head){
    if (head->front == nullptr){
        return insertBeforeHead(val, head);
    }
    
    Node* tail = head;
    while(tail->front != nullptr){
        tail = tail->front;
    }
    
    Node* temp = new Node(val,tail->back,tail);
    tail->back->front = temp;
    tail->back = temp;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convert_arr_to_DLL(arr);
    
    Node* modHead = insertBeforeTail(8,head);
    print(modHead);
    return 0;
}