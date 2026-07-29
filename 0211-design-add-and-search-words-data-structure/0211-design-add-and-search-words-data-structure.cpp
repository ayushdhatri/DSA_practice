class WordDictionary {
public:
struct Node{
    vector<Node*>child;
    int word_end;
    Node(){
        child.resize(26);
        for(int i = 0;i<26;i++){
            this->child[i] = NULL;
            word_end = 0;
        }
    }
};

struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }

    void insertWord(string s){
        int n = s.size();
        Node* curr = root;
        for(int i = 0;i<n;i++){
            int x = s[i] - 'a';
            if(curr->child[x] == NULL){
                curr->child[x] = new Node();
            }
            curr = curr->child[x];
        }
        curr->word_end+=1;
    }
    bool dfs(Node* curr, string s, int index){
        if(curr == NULL)return false;
        if(index == s.size()){
            return curr->word_end > 0;
        }
        if(s[index] == '.'){
            for(int i = 0;i<26;i++){
                if(dfs(curr->child[i], s,index+1)) return true;
            }
            return false;
        }
        
        int x = s[index] - 'a';
        if(x < 26 && curr->child[x] == NULL)return false;
        return dfs(curr->child[x], s, index+1);
    }
    bool findWord(string s){
        Node* curr = root;
        return dfs(curr, s, 0);

    }

}wordTrie;
    WordDictionary() {
        // we have already initlize wordtrie;
        
    }
    
    void addWord(string word) {
        wordTrie.insertWord(word);
        
    }
    
    bool search(string word) {
        return wordTrie.findWord(word);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */