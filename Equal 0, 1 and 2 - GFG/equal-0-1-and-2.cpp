//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        int n = str.size();
        int countz=0;
        int counto=0;
        int countt=0;
        int delta10 = counto-countz;
        int delta21 = countt-counto;
        int ans = 0;
        map<pair<int, int>,int>freq;
        freq[{delta10, delta21}]=1;
        for(int i = 0;i<n;i++)
        {
            if(str[i]=='0')countz++;
            else if(str[i]=='1')
                counto++;
            else
                countt++;
            int newdelta10 =  counto-countz;
            int newdelta21 =  countt-counto;
            if(freq.find({newdelta10, newdelta21})!=freq.end())
            {
                ans+=freq[{newdelta10, newdelta21}];
            }
            freq[{newdelta10, newdelta21}]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends