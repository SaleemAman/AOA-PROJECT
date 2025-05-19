#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node class
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search for a word
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Check if a prefix exists
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return true;
    }
};

// Main function with menu
int main() {
    Trie trie;
    int choice;
    string word;

    while (true) {
        cout << "\n--- Trie Menu ---\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Check Prefix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                trie.insert(word);
                cout << "Word inserted.\n";
                break;

            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                if (trie.search(word))
                    cout << "Word found in Trie.\n";
                else
                    cout << "Word NOT found.\n";
                break;

            case 3:
                cout << "Enter prefix to check: ";
                cin >> word;
                if (trie.startsWith(word))
                    cout << "Prefix exists in Trie.\n";
                else
                    cout << "Prefix does NOT exist.\n";
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
