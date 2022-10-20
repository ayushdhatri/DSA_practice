class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        if(s.size()==0)
            return ans;
        for(int i=0;i<s.size();i++)
        {
          char ch = s[i];
          if(ch=='(')
          {
              if(st.size()>0)
                  ans+='(';
              st.push(ch);
          }
          else
          {
              if(st.size()>1)
              {
                  ans+=')';
              }
              st.pop();
            }
            
        }
        return ans;
        
        
    }
};