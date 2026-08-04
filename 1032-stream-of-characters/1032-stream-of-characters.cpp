#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StreamChecker {
public:
    struct Node {
        Node* child[26];
        bool is_end;

        Node() {
            this->is_end = false;
            for (int i = 0; i < 26; i++) {
                this->child[i] = NULL;
            }
        }
    };

    struct Trie {
        Node* root;

        Trie() {
            root = new Node();
        }

        // Insert word in REVERSE order
        void insertWord(const string& wordToInsert) {
            Node* curr = root;
            int n = wordToInsert.size();

            // Iterate from last character down to first
            for (int i = n - 1; i >= 0; i--) {
                int charIndex = wordToInsert[i] - 'a';
                if (curr->child[charIndex] == NULL) {
                    curr->child[charIndex] = new Node();
                }
                curr = curr->child[charIndex];
            }
            curr->is_end = true;
        }

        // Search backward from the newest stream character
        bool query(const string& stream) {
            Node* curr = root;
            int n = stream.size();

            // Walk backward through stream history
            for (int i = n - 1; i >= 0; i--) {
                int charIndex = stream[i] - 'a';
                if (curr->child[charIndex] == NULL) {
                    return false; // Branch doesn't exist in reverse Trie
                }
                curr = curr->child[charIndex];
                if (curr->is_end) {
                    return true; // Match found!
                }
            }
            return false;
        }
    } tt;

    string streamHistory;

    StreamChecker(vector<string>& words) {
        streamHistory = "";
        for (const string& word : words) {
            tt.insertWord(word);
        }
    }

    bool query(char letter) {
        streamHistory += letter;
        return tt.query(streamHistory);
    }
};