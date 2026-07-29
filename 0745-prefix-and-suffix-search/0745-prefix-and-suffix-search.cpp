#include <vector>
#include <string>

using namespace std;

class WordFilter {
private:
    struct Node {
        Node* child[27]; // 0-25 for 'a'-'z', 26 for '{'
        int max_index;

        Node() {
            max_index = -1;
            for (int i = 0; i < 27; i++) {
                child[i] = nullptr;
            }
        }
    };

    struct Trie {
        Node* root;

        Trie() {
            root = new Node();
        }

        void insertWord(const string& s, int index) {
            Node* curr = root;
            curr->max_index = index; // Update root's max index
            
            for (char ch : s) {
                int x = ch - 'a'; // '{' - 'a' equals 26
                if (curr->child[x] == nullptr) {
                    curr->child[x] = new Node();
                }
                curr = curr->child[x];
                curr->max_index = index; // Overwrite with latest index
            }
        }

        int findSuffixPrefix(const string& s) {
            Node* curr = root;
            for (char ch : s) {
                int x = ch - 'a';
                if (curr->child[x] == nullptr) {
                    return -1;
                }
                curr = curr->child[x];
            }
            return curr->max_index;
        }
    } wordTrie;

public:
    WordFilter(vector<string>& words) {
        for (int index = 0; index < words.size(); index++) {
            string word = words[index];
            int n = word.size();
            
            // Insert all suffix + "{" + word variations
            // Loop up to n so we also include the empty suffix ""
            for (int i = 0; i <= n; i++) {
                string suffix = word.substr(i);
                string combWord = suffix + "{" + word;
                wordTrie.insertWord(combWord, index);
            }
        }
    }
    
    int f(string pref, string suff) {
        string combWord = suff + "{" + pref;
        return wordTrie.findSuffixPrefix(combWord);
    }
};