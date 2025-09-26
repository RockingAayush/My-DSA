#include <iostream>
using namespace std;

struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    Node *get(int bit){
        return links[bit];
    }

    void put(int bit, Node *node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }

public:
    void insert(int num){
        Node *node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int getMax(int num){
        Node *node = root;
        int max = 0;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)){
                max |= (1 << i);
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return max;
    }
};

int main()
{
    Trie trie;

    // Insert numbers into the trie
    trie.insert(3); // binary: 000...0011
    trie.insert(12); // binary: 000...1010
    trie.insert(5); // binary: 000...0101

    // Query maximum XOR
    int query = 6; // binary: 000...0110
    int result = trie.getMax(query);

    cout << "Maximum XOR of " << query << " with trie elements = " << result << endl;

    return 0;
}
