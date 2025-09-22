#include <bits/stdc++.h>
using namespace std;

class minStack{
    private:
    stack<pair<int,int>> st;

    private:
    void push(int a,int b){
        st.push({a,b});
    }

    void pop(){
        st.pop();
    }

    pair<int,int> top(){
        if (!st.empty()) {
            return st.top();
        }
        return {-1, -1};
    }
};

int main(){
    
    return 0;
}