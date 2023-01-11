class Solution {
public:
    bool match(char ch1, char ch2)
    {
        if(ch1=='}'&&ch2=='{')return true;
        if(ch1==')'&&ch2=='(')return true;
        if(ch1==']'&&ch2=='[')return true;
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(int i =0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch=='('||ch=='{'||ch=='[')
                st.push(ch);
            else
            {
                if(st.size()!=0&&match(ch, st.top()))
                    st.pop();
                else
                    return false;
            }
        }
        
        
        
        
        return st.size()==0;
        
    }
};