class Solution {
public:
    bool check(unordered_map<char, int>&freq)
    {
        for(auto x: freq)
        {
            if(x.second>1)
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j=0;
        int ans=0;
        unordered_map<char, int>freq;
        while(j<n)
        {
            freq[s[j]]++;
            if(check(freq))
            {
                int temp = freq.size();
                ans = max(ans, temp);
                j++;
            }
            else
            {
                while(check(freq)==false)
                {
                    if(freq[s[i]]==1)
                        freq.erase(s[i]);
                    else
                        freq[s[i]]--;
                    i++;
                }
                 int temp = freq.size();
                ans = max(ans, temp);
                j++;
            }
        }
        return ans;
        
        
        
        
    }
};