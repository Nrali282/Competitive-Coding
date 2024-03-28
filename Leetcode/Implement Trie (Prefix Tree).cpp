

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input :
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]

Output :
[null, null, true, false, true, null, true]

Explanation :
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

    ***********************************************************
*/


#include <bits/stdc++.h>

class Node {
public:
    bool eow;
    Node* children[26];

    Node() {
        eow = false;
        memset(children,0,sizeof(children));
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == NULL) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->eow;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */