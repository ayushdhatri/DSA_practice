class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> word_map;
        for(int i  = 0;i<n;i++){
            word_map[words[i]] = i;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            string rev_word = words[i];
            reverse(rev_word.begin(), rev_word.end());
            if(word_map.find(rev_word) != word_map.end()&& word_map[rev_word] !=i )
            {
                // it means reverse word exist
                ans++;
                word_map.erase(words[i]);
                word_map.erase(rev_word);
            }
        }

        return ans;
        
    }
};