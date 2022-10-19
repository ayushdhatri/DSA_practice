class Solution {
public:
    string makeGood(string s) {
        if(s.size()==0||s.size()==1)
        {
            return s;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.size()==0)
                st.push(s[i]);
            else
            {
                char ch  = s[i];
                if(ch>='A'&&ch<='Z')// check if this character is upper 
                {
                  char temp = tolower(ch);
                  if(st.top()==temp)
                        st.pop();
                  else
                        st.push(ch);
                }
                else // it is lower character
                {
                    char temp  = toupper(ch);
                    if(st.top()==temp)
                        st.pop();
                    else
                        st.push(ch);
                }
            }
            
        }
        string ans="";
        while(st.size()!=0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};