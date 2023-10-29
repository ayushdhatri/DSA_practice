//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        unordered_map<int, int>freq;
        int i = 0;
        int j = 0;
        vector<int>ans;
        while(j<n){
            freq[a[j]]+=1;
            if((j-i+1)<k){
                j++;
            }
            else if((j-i+1)==k){
                ans.push_back(freq.size());
                freq[a[i]]--;
                if(freq[a[i]]==0)freq.erase(a[i]);
                i++;
                j++;
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends