class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==1)
        {
            if(s[0]!='0')
                return 1;
        }
        vector<int>dp(n, 0);
        if(s[0]!='0')
            dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                string temp = "";
                temp+=s[i-1];
                temp+=s[i];
                cout<<temp<<endl;
                int number = stoi(temp);
                if(number>=10&&number<=26)
                {
                    if(i==1)
                        dp[i]++;
                    else
                        dp[i]+=dp[i-2];
                }
            }
            else
            {
                dp[i]+=dp[i-1];
                string temp = "";
                temp+=s[i-1];
                temp+=s[i];
                int number = stoi(temp);
                
                if(number>=10&&number<=26){
                    if(i==1)
                        dp[i]++;
                    else
                        dp[i]+=dp[i-2];
                    
                }   
                
            }
        }
        return dp[n-1];
        
    }
};