class Solution {
public:
    bool vowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxans = INT_MIN;
        int count=0;
        while(j<n)
        {
            char ch = s[j];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                count++;
            if((j-i+1)<k)
                j++;
            else if((j-i+1)==k)
            {
                maxans = max(maxans, count);
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    count--;
                }
                i++;
                j++;
            }
          }
        return maxans;
        
    }
};