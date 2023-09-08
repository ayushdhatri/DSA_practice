//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void solve(string &s, string &ans){
        //aabc
        int i = 0;
        int n = s.size();
        while(i<n){
            int j = i;
            int count = 0;
            //0 0 
            do{
                count++;
                j++;
            }while(j<n&&s[i]==s[j]);
            ans+=s[i];
            ans+=to_string(count);
            
            i = j;
        }
        
    }
    string encryptString(string s){
//     // code here
    
//     // aabc
//     2 a
//     1 b
//     1 c
//     2a1b1c
//     1c1b2a
//   a5
//   5a
//   // count character and write its frequenncy in front of it
//   abcde
//   a1b1c1d1e1
//   1e1d1c1b1a
    string ans = "";
    solve(s, ans);//step 1
    reverse(ans.begin(), ans.end());
    return ans;
   
    
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
	    string s;
		cin>>s;
		Solution ob;
		string ans = ob.encryptString(s);
		cout<<ans<<endl;
	}
}

// } Driver Code Ends