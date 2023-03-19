

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

    ***********************************************************
*/


#include <bits/stdc++.h>

class Node {
public:
    Node* children[26];
    bool eow;

    Node() {
        memset(children,0,sizeof(children));
        eow = false;
    }
};
class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
        return searchHelper(word,root);
    }

    bool searchHelper(string word,Node* node) {
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(ch == '.') {
                for(auto c : node->children) {
                    if(c && searchHelper(word.substr(i+1),c))
                        return true;
                }
                return false;
            }
            int idx = ch - 'a';
            if(node->children[idx] == NULL)
                return false;
            node = node->children[idx];
        }
        return node->eow;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */