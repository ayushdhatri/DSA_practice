class Solution {
public:
    int minways(vector<int>&days, vector<int>&costs, int i, int finalday, vector<vector<int>>&dp)
    {
        if(i==days.size())return 0;
        // this presentday is aleady under a valid pass
        if(dp[i][finalday]!=-1)
            return dp[i][finalday];
        if(days[i]<=finalday)
            return 0+minways(days, costs, i+1,finalday,dp);
        // lets buy a single day pass
        int ans = 1e9;
        int way1  = costs[0]+minways(days, costs, i+1, days[i],dp);
        int way2  = costs[1]+minways(days, costs, i+1,days[i]+6,dp);
        int way3 = costs[2]+minways(days, costs, i+1, days[i]+29,dp);
        ans = min(way1, min(way2, way3));
        return dp[i][finalday]=ans;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxelement = *max_element(days.begin(), days.end());
        vector<vector<int>>dp(n, vector<int>(maxelement+30,-1));
       return  minways(days, costs, 0,0,dp);
        
        
    }
};