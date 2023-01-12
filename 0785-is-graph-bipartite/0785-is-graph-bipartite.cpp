class Solution {
public:
    bool dfs(int vertex, vector<int>&color, vector<bool>&visited, vector<vector<int>>&graph)
    {
        visited[vertex]=true;
        bool ans = true;
        
        for(int i = 0;i<graph[vertex].size();i++)
        {
            int adjnode = graph[vertex][i];
            if(visited[adjnode]==false)
            {
                color[vertex]==1?color[adjnode]=0:color[adjnode]=1;
                ans = dfs(adjnode, color, visited, graph);
            }
            else
            {
                if(color[adjnode]!=-1&&color[adjnode]==color[vertex])
                    return false;
            }
            
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int V = graph.size(); 
       vector<bool>visited(V, false);
        vector<int>color(V, -1);
        for(int i =0;i<V;i++)
        {
            if(visited[i]==false)
            {
                color[i]=1;
                bool temp = dfs(i, color, visited, graph);
                if(temp==false)
                    return false;
            }
        }
        return true;
        
    }
};