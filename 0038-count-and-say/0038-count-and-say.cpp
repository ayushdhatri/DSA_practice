class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
                return "1";
        
        string s=countAndSay(n-1);
        
        int cnt=1;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==s[i+1])
                    cnt++;
            else{
                    tmp+=to_string(cnt) + s[i] ;
                    cnt=1;
            }
        }
        return tmp;
    }
};