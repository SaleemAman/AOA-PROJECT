#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Clean input (remove spaces, convert to lowercase)
    void cleanInput(string& str) {
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    // Insert a word
    void insert(string word) {
        cleanInput(word);
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        cout << "[DEBUG] Inserted: " << word << endl;
    }

    // Search a word
    bool search(string word) {
        cleanInput(word);
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        cout << "[DEBUG] Searched: " << word << endl;
        return node->isEndOfWord;
    }

    // Check prefix
    bool startsWith(string prefix) {
        cleanInput(prefix);
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        cout << "[DEBUG] Prefix checked: " << prefix << endl;
        return true;
    }

    // Destructor
    ~Trie() {
        deleteNode(root);
    }

    void deleteNode(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteNode(pair.second);
        }
        delete node;
    }
};

// Main Menu
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
        cin.ignore(); // Clear newline

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                getline(cin, word);
                trie.insert(word);
                break;

            case 2:
                cout << "Enter word to search: ";
                getline(cin, word);
                if (trie.search(word))
                    cout << "Word found in Trie.\n";
                else
                    cout << "Word NOT found.\n";
                break;

            case 3:
                cout << "Enter prefix to check: ";
                getline(cin, word);
                if (trie.startsWith(word))
                    cout << "Prefix exists in Trie.\n";
                else
                    cout << "Prefix does NOT exist.\n";
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
