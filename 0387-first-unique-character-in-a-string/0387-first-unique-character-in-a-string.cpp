class Solution {
public:
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
        return approach1(s);
        
    }
};