#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    public:
    Node(int val1){
        val = val1;
        left = NULL;
        right = NULL;
    }

    Node(int val1,Node* left1,Node* right1){
        val = val1;
        left = left1;
        right = right1;
    }
};

int main(){
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);

    cout << root->val;
    cout << root->left->val;
    cout << root->right->val;
    return 0;
}