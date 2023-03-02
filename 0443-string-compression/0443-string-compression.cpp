class Solution {
public:
    int compress(vector<char>& chars) {
        string ans="";
        int n = chars.size();
        int count=1;
        if(chars.size()==1)
            return chars.size();
        for(int i=0;i<n-1;i++)
        {
            if(chars[i]==chars[i+1])
            {
                count++;
                if(i==n-2)
                {
                    ans+=chars[i];
                    if(count!=1)
                        ans+=to_string(count);
                }
            }
            else
            {
                ans+=chars[i];
                if(count!=1)
                    ans+=to_string(count);
                if(i==n-2)
                {
                    ans+=chars[n-1];
                }
                count=1;
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            chars[i]=ans[i];
        }
        return ans.size();
    }
};