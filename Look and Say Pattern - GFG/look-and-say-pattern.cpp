//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string series(int n)
    {
        if(n==1)
        return "1";
        string ans="";
        string prev = series(n-1);
        int i = 0;
        int count=1;
        while(i<prev.size())
        {
            if(prev[i]==prev[i+1]){
            count++;
            i++;
            }
            else
            {
                ans+=to_string(count);
                ans+=prev[i];
                count=1;
                i++;
            }
        }
        return ans;
    }
    string lookandsay(int n) {
        // code here
        return series(n);
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends