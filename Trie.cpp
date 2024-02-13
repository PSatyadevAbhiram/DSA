#include<unordered_map>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
        unordered_map<char, TrieNode*>  children;
        bool isEndofWord;

        TrieNode(){
            isEndofWord = false;
        }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string word){
            TrieNode* current = root;
            for(char c : word){
                if(current->children.find(c) == current->children.end()){
                    current->children[c] = new TrieNode();
                }
                current = current->children[c];
            }
            current->isEndofWord = true;
        }

        bool search(string word){
            TrieNode* current = root;
            for(char c : word){
                if(current->children.find(c) == current->children.end()){
                    return false;
                }
                current = current->children[c];
            }
            return current != nullptr && current->isEndofWord;
        }

        bool startsWith(string prefix){
            TrieNode* current = root;
            for(char c: prefix){
                if(current->children.find(c) == current->children.end()){
                    return false;
                }
                current = current->children[c];
            }
            return current != nullptr;
        }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("app");

    cout << trie.search("apple") << endl;    // Output: 1 (true)
    cout << trie.search("app") << endl;      // Output: 1 (true)
    cout << trie.search("banana") << endl;   // Output: 1 (true)
    cout << trie.search("ban") << endl;      // Output: 0 (false)
    cout << trie.startsWith("ban") << endl;  // Output: 1 (true)
    cout << trie.startsWith("apx") << endl;  // Output: 0 (false)

    return 0;
}