class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>lp;
        int count=0;
        if(s.size()==0)
            return 0;
        
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch=='(') // character can be either left parenthsesis 
            {
                lp.push(ch);
            }
            else
            {
                if(lp.size()==0)
                    count++;
                else
                    lp.pop();
            }
        }
        count+=lp.size();
        return count;
        
    }
};