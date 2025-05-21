
What is a Trie?

A Trie is a tree-like data structure used to store words, especially useful for searching by prefixes.
Each path from the root to a node represents a word or a part of it.
It is commonly used in:

•Autocomplete
•Spell check
•Word search engines
•IP routing
----------------------------

Why Use a Trie?

•Fast word search and prefix matching
•Saves memory for large word lists with common beginnings
•Easy to implement autocomplete systems
•Supports efficient insertion and deletion
------------------------------

How Trie Works

Suppose we insert the words:
"cat", "car", and "bat"

Trie will look like:

root
       /    \
      c      b
     /        \
    a          a
   / \          \
  t   r          t

•Nodes are created character by character
•Shared prefixes use the same path
•The last node of each word is marked as the end
-----------------------------&

Operations in Trie

1. Insert(word)
Go through each character
Create a node if it doesn't exist
Mark the final character node as the end of the word


2. Search(word)
Go through each character
If the path exists and the last character node is marked as end, word exists


3. startsWith(prefix)
Traverse through the characters of the prefix
If the path exists, return true (prefix found), else false


4. Delete(word) (not shown in code but possible)
Unmark the end node
Remove nodes that are not part of any other word
------------------------------


Advantages of Trie

Quick searches and prefix matches
Great for dictionary-based applications
Stores words in sorted form naturally


Disadvantages

Uses more memory for small word sets
Slightly complex to implement than arrays or hash maps
-------------------------------

Short Code Explanation
This C++ code builds a Trie with basic functionality.
TrieNode: Each node stores children and a flag for word-end.
Trie: Manages insertion, search, and prefix check.
cleanInput(): Removes spaces and makes input lowercase.
insert(): Adds the word letter by letter into the Trie.
search(): Checks if a word exists in the Trie.
startsWith(): Checks if any word starts with the given prefix.
main(): Shows a menu to use all features interactively.


The code is simple, efficient, and suitable for console-based Trie testing or learning.


