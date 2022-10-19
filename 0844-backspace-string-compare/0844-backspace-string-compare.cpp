class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>t1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
            {
                s1.push(s[i]);
            }
            else
            {
                if(s1.size()!=0)
                    s1.pop();
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]!='#')
            {
                t1.push(t[i]);
            }
            else
            {
                if(t1.size()!=0)
                    t1.pop();
            }
        }
        return s1==t1;
        
        
        
    }
};