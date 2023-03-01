class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int>hash1(26, 0);
        vector<int>hash2(26, 0);
        for(int i=0;i<words[0].size();i++)
        {
            hash1[words[0][i]-'a']++;
        }
        for(int i=1;i<words.size();i++)
        {
            for(int j = 0;j<words[i].size();j++)
            {
                hash2[words[i][j]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                hash1[i]=min(hash1[i], hash2[i]);
                hash2[i]=0;
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            int count = hash1[i];
            while(count--)
            {
                string temp=""; 
                    temp+=(i+'a');
                ans.push_back(temp);
            }
        }
        return ans;
    }
};