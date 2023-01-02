class Solution {
public:
    void dfs(int vertex, vector<bool>&visited, vector<vector<int>>&isConnected)
    {
        visited[vertex]=true;
        for(int i=0;i<isConnected[vertex].size();i++)
        {
            if(visited[i]==false&&isConnected[vertex][i]==1) {
                dfs(i,visited,isConnected);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertex = isConnected.size();
        vector<bool>visited(vertex, false);
        int ans =0;
        for(int i=0;i<vertex;i++)
        {
            if(visited[i]==false)
            {
                ans++;
                dfs(i,visited,isConnected);
            }
        }
        return ans;
        
    }
};