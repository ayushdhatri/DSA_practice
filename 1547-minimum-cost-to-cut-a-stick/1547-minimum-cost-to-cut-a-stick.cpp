class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        // Base case: no cuts between i and j
        if(i + 1 == j) {
            return 0;
        }
        
        // Already computed
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int minCost = INT_MAX;
        
        // Try all possible cuts between i and j
        for(int k = i + 1; k < j; k++) {
            int cost = (cuts[j] - cuts[i]) + solve(i, k, cuts, dp) + solve(k, j, cuts, dp);
            minCost = min(minCost, cost);
        }
        
        return dp[i][j] = minCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        // Add boundaries and sort
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        return solve(0, m - 1, cuts, dp);
    }
};