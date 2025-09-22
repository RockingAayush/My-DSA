#include <iostream>
#include <string>
using namespace std;

// ----------------- Trie Node -----------------
struct Node {
    // Each node has 26 possible links (for 'a' to 'z')
    Node* links[26];
    // Marks whether this node corresponds to the end of a word
    bool flag = false;

    // Checks if the current node has a child corresponding to character 'ch'
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Creates a new node link for character 'ch'
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Returns the next node linked with character 'ch'
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Marks the end of a word
    void setEnd() {
        flag = true;
    }

    // Checks if this node is the end of a word
    bool isEnd() {
        return flag;
    }
};

// ----------------- Trie Class -----------------
class Trie {
private:
    Node* root; // Root node represents an empty string

public:
    Trie() {
        root = new Node(); // Initialize root
    }
    
    // Insert a word into the Trie
    // Time Complexity: O(L), where L = length of the word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If the character path doesn't exist, create it
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd(); 
    }
    
    // Search if a word exists in the Trie
    // Returns true only if the complete word is found
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false; // Word not present
            }
            node = node->get(word[i]);
        }
        return node->isEnd(); // Must be an end-of-word
    }
    
    // Check if there exists any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false; // Prefix not present
            }
            node = node->get(prefix[i]);
        }
        return true; // Prefix exists
    }
};

// ----------------- Main Function -----------------
int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Search for complete words
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'ball': " << (trie.search("ball") ? "Found" : "Not Found") << endl;
    cout << "Search 'batman': " << (trie.search("batman") ? "Found" : "Not Found") << endl;

    // Prefix queries
    cout << "StartsWith 'ap': " << (trie.startsWith("ap") ? "Yes" : "No") << endl;
    cout << "StartsWith 'bat': " << (trie.startsWith("bat") ? "Yes" : "No") << endl;
    cout << "StartsWith 'cat': " << (trie.startsWith("cat") ? "Yes" : "No") << endl;

    return 0;
}
