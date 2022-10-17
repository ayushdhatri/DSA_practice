class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i=s.size()-1;
        while(i>=0)
        {
            if(s[i]==' ')
                i--;
            else
                break;
            
        }
        int len=0;
        while(i>=0)
        {
            if(s[i]!=' ')
                len++;
            else
                break;
            i--;
        }
        
        return len;
        
    }
};