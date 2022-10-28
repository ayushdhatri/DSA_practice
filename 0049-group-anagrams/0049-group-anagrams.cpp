class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int  n = strs.size();
        vector<pair<string, string>>words;
        for(int i=0;i<n;i++) //Tc = n^2logn
        {
            string sortedword = strs[i];
            sort(sortedword.begin(), sortedword.end());
            words.push_back({strs[i], sortedword});
        }
        vector<vector<string>>ans;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true)continue;
            vector<string>temp;
            temp.push_back(strs[i]);
            for(int j=i+1;j<n;j++)
            {
                if(words[j].second==words[i].second) {
                    temp.push_back(strs[j]);
                    visited[j]=true;
                }
             }
            ans.push_back(temp);
        }
        
        
        
        
        return ans;
        
    }
};