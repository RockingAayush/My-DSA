#include <iostream>
#include <string>
using namespace std;

// ----------------- Node Structure -----------------
// Each Node represents one character in the Trie.
// It contains links to possible next characters, 
// and counters to keep track of word frequencies.
struct Node {
    Node* links[26];   // Pointers to 26 children (for 'a' to 'z')
    int cntEndWith = 0; // Number of words ending at this node
    int cntPrefix = 0;  // Number of words sharing this prefix

    // Checks if this node already has a child for 'ch'
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Creates a new child node for character 'ch'
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Returns the child node corresponding to 'ch'
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Increments word-end counter (word completed here)
    void increaseEnd() {
        cntEndWith++;
    }

    // Increments prefix counter (this prefix was traversed)
    void increasePrefix() {
        cntPrefix++;
    }

    // Decrements word-end counter (used during erase)
    void deleteEnd() {
        cntEndWith--;
    }

    // Decrements prefix counter (used during erase)
    void reducePrefix() {
        cntPrefix--;
    }

    // Returns how many words end at this node
    int getEnd() {
        return cntEndWith;
    }
    
    // Returns how many words share this prefix
    int getPrefix() {
        return cntPrefix;
    }
};

// ----------------- Trie Class -----------------
// Implements operations on the Trie such as insert,
// word count, prefix count, and erase.
class Trie {
private:
    Node* root; // Root node is an empty "start" state

public:
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    // For each character:
    // - If the link doesn't exist, create it
    // - Move forward and increment prefix count
    // Finally, increment end count at last character
    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!(node->containsKey(word[i]))) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix(); // prefix count = #words passing through
        }
        node->increaseEnd(); // marks a complete word
    }

    // Counts how many times a given word has been inserted
    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0; // path doesn't exist → word not present
            }
        }
        return node->getEnd();
    }

    // Counts how many words start with a given prefix
    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0; // prefix doesn't exist
            }
        }
        return node->getPrefix();
    }

    // Erases one occurrence of a word
    // Walk down the path of the word:
    // - Decrement prefix counts
    // At the end node:
    // - Decrement end count
    void erase(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            } else return; // word not found → nothing to erase
        }
        node->deleteEnd();
        return; 
    }
};

// ----------------- Main Function -----------------
int main() {
    Trie trie;

    // Words to test the Trie
    string w1 = "apple";
    string w2 = "app";
    string w3 = "apricot";
    string w4 = "bat";
    string w5 = "ball";
    string w6 = "banana";

    // -------- Insert operations --------
    // Insert words (with duplicates for "app")
    trie.insert(w1);
    trie.insert(w2);
    trie.insert(w2);   // "app" inserted twice
    trie.insert(w3);
    trie.insert(w4);
    trie.insert(w5);

    // -------- Word frequency queries --------
    cout << "Count of 'apple': " << trie.countWordsEqualTo(w1) << endl;  // 1
    cout << "Count of 'app': " << trie.countWordsEqualTo(w2) << endl;    // 2
    cout << "Count of 'apricot': " << trie.countWordsEqualTo(w3) << endl;// 1
    cout << "Count of 'bat': " << trie.countWordsEqualTo(w4) << endl;    // 1
    cout << "Count of 'ball': " << trie.countWordsEqualTo(w5) << endl;   // 1
    cout << "Count of 'banana': " << trie.countWordsEqualTo(w6) << endl; // 0

    // -------- Prefix frequency queries --------
    string ap = "ap";
    string ba = "ba";
    string cat = "cat";
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith(ap) << endl;  // 4 ("apple", "app", "app", "apricot")
    cout << "Words starting with 'ba': " << trie.countWordsStartingWith(ba) << endl;  // 2 ("bat", "ball")
    cout << "Words starting with 'cat': " << trie.countWordsStartingWith(cat) << endl;// 0

    // -------- Erase operations --------
    trie.erase(w2); // remove one occurrence of "app"
    cout << "After erasing one 'app': " << trie.countWordsEqualTo(w2) << endl;  // 1
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith(ap) << endl; // 3

    trie.erase(w2); // remove "app" again
    cout << "After erasing 'app' completely: " << trie.countWordsEqualTo(w2) << endl; // 0
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith(ap) << endl; // 2

    return 0;
}
