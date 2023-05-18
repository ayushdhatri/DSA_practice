//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> LIS(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int>dp(n);
	    dp[0]=1;
	    for(int i = 1;i<n;i++)
	    {
	        bool flag  = false;
	        int temp = 1;
	       
	       for(int j = i-1;j>=0;j--)
	       {
	           if(nums[i]>nums[j])
	           {
	               flag = true;
	               temp = max(temp, dp[j]);
	           }
	       }
	       if(flag)
	            dp[i]= temp+1;
	       else
	            dp[i]=1;
	    }
	    return dp;
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	      int n = nums.size();
	    vector<int>nums2 = nums;
	    reverse(nums2.begin(), nums2.end());
	    vector<int>dp1 = LIS(nums);
	    vector<int>dp2 = LIS(nums2);
	    reverse(dp2.begin(), dp2.end());
	    int ans = INT_MIN;
	    for(int i= 0;i<n;i++)
	    {
	        ans = max(ans, dp1[i]+dp2[i]-1);
	    }
	    return ans;
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends