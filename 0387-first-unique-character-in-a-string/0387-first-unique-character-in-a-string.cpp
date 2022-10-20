class Solution {
public:
    int approach2(string s)
    {
        vector<int>freq(26, 0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
       for(int i=0;i<s.size();i++)
       {
           if(freq[s[i]-'a']==1)
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