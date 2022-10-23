class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int>freq1;
    for(int i=0;i<p.size();i++)
    {
        char ch = p[i];
        if(freq1.find(ch)==freq1.end())// elemtn is not present in the string
            freq1.insert({ch, 1});
        else
            freq1[ch]++;
    }
    unordered_map<char, int>freq2;
    int i=0;
    int j=0;
    int k = p.size();
    int n = s.size();
    vector<int>ans;
    while(j<n)
    {
        if(freq2.find(s[j])==freq2.end())// elemtn is not present in the string
            freq2.insert({s[j], 1});
        else
            freq2[s[j]]++;
        if((j-i+1)<k)
            j++;
        else if((j-i+1)==k)
        {
            if(freq1==freq2)
                ans.push_back(i);
            if(freq2[s[i]]==1)
                freq2.erase(s[i]);
            else
                freq2[s[i]]--;
            i++;
            j++;
        }
    }
    
    
    return ans;
        
    }
};