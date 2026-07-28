class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // Frequency map is enough — vector<int> of indices isn't needed
        unordered_map<string, int> freq;
        for (const string& w : words) {
            freq[w]++;
        }
        
        int ans = 0;
        bool has_center = false;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            
            // Skip if we already processed and erased this word
            if (freq.find(word) == freq.end()) continue;

            string rev_word = word;
            reverse(rev_word.begin(), rev_word.end());

            if (word == rev_word) {
                int count = freq[word];
                // Pair up as many as possible (even count)
                ans += (count / 2) * 4; 
                
                // If there's an odd one left over, we can use ONE as the center
                if (count % 2 == 1) {
                    has_center = true;
                }
                
                freq.erase(word);
            } 
            else if (freq.find(rev_word) != freq.end()) {
                // Each matching pair contributes 4 characters (2 words * 2 letters)
                int pairs = min(freq[word], freq[rev_word]);
                ans += pairs * 4;
                
                freq.erase(word);
                freq.erase(rev_word);
            }
        }

        // Add 2 if we found at least one un-paired identical word for the center
        if (has_center) {
            ans += 2;
        }

        return ans;
    }
};