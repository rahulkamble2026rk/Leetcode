// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) 
//     {
        
//     }
// }; 

class TrieNode {
public:
    TrieNode* links[2];  // only 0 or 1

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }

    TrieNode* get(int bit) {
        return links[bit];
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->containsKey(toggledBit)) {
                maxNum |= (1 << i);
                node = node->get(toggledBit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxXOR = 0;

        // Insert all numbers in Trie
        for (int num : nums) {
            trie.insert(num);
        }

        // For each number, find best XOR
        for (int num : nums) {
            maxXOR = max(maxXOR, trie.getMaxXOR(num));
        }

        return maxXOR;
    }
};
