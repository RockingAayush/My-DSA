#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec1;
    int element, size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an element: ";
        cin >> element;
        vec1.push_back(element); 
    }
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter+2/*2nd position from beginning*/,23);
    vec1.insert(vec1.begin() /*This is an iterator*/,2/*Number of copies to be inserted*/,45);
    display(vec1);
    vec1.pop_back();
    display(vec1);
    return 0;
}