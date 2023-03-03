class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i=0, j=0;
        if(m>n)
            return -1;
        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                bool flag=true;
                while(j<m)
                {
                    if(haystack[i+j]!=needle[j])
                    {
                        flag = false;
                        break;
                    }
                    j++;
                }
                if(flag)
                    return i;
                else
                {
                    j=0;
                }
            }
            i++;
        }
        return -1;
        
    }
};