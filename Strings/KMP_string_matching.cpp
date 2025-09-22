#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string &pattern){
    int m = pattern.size();
    vector<int> lps(m,0);

    int len = 0; //Length of the longest prefix
    int i = 1;
    
    while (i < m){
        if (pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                // fall back in the lps array
                len = lps[len - 1];
            } 
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;        
}

// KMP search function
void KMPSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = buildLPS(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // look for next possible match
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // shift pattern using lps
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    KMPSearch(text, pattern);

    return 0;
}


//Refer : https://youtu.be/ynv7bbcSLKE?si=ZNKHZZfTAxKH67SQ