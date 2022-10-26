//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    
    unordered_map<char, int>freq;
    int i=0, j=0;
    int n = s.size();
    int ans = -1;
    while(j<n)
    {
        if(freq.find(s[j])==freq.end())
            freq.insert({s[j],1});
        else
            freq[s[j]]++;
        if(freq.size()<k)
            j++;
        else if(freq.size()==k)
        {
            ans = max(ans, j-i+1);
            j++;
        }
        else
        {
            while(freq.size()>k)
            {
                if(freq[s[i]]==1)
                    freq.erase(s[i]);
                else
                    freq[s[i]]--;
                i++;    
            }
            if(freq.size()==k)
            ans = max(ans, j-i+1);
            j++;    
        }
    }
    return ans;
    
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends