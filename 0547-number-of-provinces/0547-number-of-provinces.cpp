class Solution {
public:
    void dfs(int pnode, int n, vector<int>adj[], vector<bool>&visited)
    {
        visited[pnode]=true;
        for(auto x: adj[pnode])
        {
            if(visited[x]==false)
            {
                dfs(x, n, adj, visited);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n, false);
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                ans++;
                dfs(i, n, adj, visited);
            }
        }
        
        return ans;
        
    }
};