class Solution {
public:
     string givelcs(string s1, string s2) {
        string lcs="";
        int n1= s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++) 
            dp[i][0]=0;
        for(int i=0;i<=n2;i++) 
            dp[0][i]=0;
        for(int index1=1;index1<=n1;index1++) {
            for(int index2=1;index2<=n2;index2++) {
                if(s1[index1-1]==s2[index2-1]){
                    dp[index1][index2]=1+dp[index1-1][index2-1];
                } 
                else {
                    dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);
                    
                }
            }
        }
        int i=n1;
        int j=n2;
        while(i>0&&j>0) {
            if(s1[i-1]==s2[j-1]) {
                lcs+=s1[i-1];
                i--;
                j--;
            }
            else {
                if(dp[i][j-1]>dp[i-1][j]) 
                    j--;
                else
                    i--;
                
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
    
    string shortestCommonSupersequence(string s1, string s2) {
        string lcs=givelcs(s1,s2);
        string ans="";
        int ptr1=0;
        int ptr2=0;
        for(char c:lcs) {
            while(s1[ptr1]!=c) 
                ans+=s1[ptr1++];
            while(s2[ptr2]!=c) 
                ans+=s2[ptr2++];
            ans+=c;
            ptr1++;
            ptr2++;
                
        }
        while(ptr1<s1.size()) {
            ans+=s1[ptr1++];
        }
        while(ptr2<s2.size()) {
            ans+=s2[ptr2++];
        }
       
        return ans;
        
        
    }
};