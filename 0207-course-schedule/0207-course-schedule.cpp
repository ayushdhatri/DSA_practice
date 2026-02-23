class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i = 0;i<m;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        // first construct the indegree
        vector<int>indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(int j = 0;j<adj[i].size();j++){
                indegree[adj[i][j]]+=1;
            }
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        // take queue
        vector<int>topo;
        while(q.size()!=0){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto x: adj[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }

        }


        return topo.size() == numCourses;


        



        
    }
};