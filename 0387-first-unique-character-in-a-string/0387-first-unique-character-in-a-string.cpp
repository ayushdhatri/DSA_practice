class Solution {
public:
    int approach2(string s)
    {
        unordered_map<char, int>freq;
        for(int i=0;i<s.size();i++)
        {
            if(freq.find(s[i])==freq.end())// element is not present
                freq.insert({s[i],1});
            else
                freq[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]]==1)
                return i;
        }
        return -1;
        
    }
    int approach1(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            bool flag = true;
            for(int j=0;j<s.size();j++)
            {
                if(i!=j&&s[i]==s[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
    int firstUniqChar(string s) {
        //return approach1(s);
        return approach2(s);
        
    }
};