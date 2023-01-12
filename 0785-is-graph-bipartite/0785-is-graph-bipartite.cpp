class Solution {
public:
    bool bfs(int vertex, vector<int>&color, vector<bool>&visited, vector<vector<int>>&graph)
    {
       visited[vertex]=true;
        queue<int>q;
        q.push(vertex);
        color[vertex]=1;
        
        while(q.size()!=0)
        {
            int currnode = q.front();
            q.pop();
            for(int i=0;i<graph[currnode].size();i++)
            {
                int adjnode = graph[currnode][i];
                if(visited[adjnode]==true)
                {
                    if(color[adjnode]!=-1&&(color[currnode]==color[adjnode]))
                        return false;
                }
                else
                {
                    color[currnode]==1?color[adjnode]=0:color[adjnode]=1;
                    visited[adjnode]=true;
                    q.push(adjnode);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool>visited(V, false);
        vector<int>color(V, -1);
        bool ans = false;
        for(int i =0;i<V;i++)
        {
            if(visited[i]==false)
            {
                bool temp = bfs(i, color, visited, graph);
                if(temp==false)
                    return false;
            }
        }
        return true;
        
        
        
    }
};