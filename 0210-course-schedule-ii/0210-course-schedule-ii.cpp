class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // here we can see that there is directed graph
        // we are not sure at this point, if cycle can exist or not
        // if it exist, 
        vector<vector<int>>g(numCourses+1);
        vector<int>indegree(numCourses+1, 0);
        vector<int>topo;
        for(int i = 0;i < prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            g[v].push_back(u);
            indegree[u]+=1;
        }
        queue<int>q;
        // find indegree
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(q.size() != 0){
            int frontNode = q.front();
            topo.push_back(frontNode);
            q.pop();
            for(auto adj : g[frontNode]){
                indegree[adj]--;
                if(indegree[adj] == 0){
                    q.push(adj);
                }
            }

        }
        cout<<topo.size();
        if(topo.size() == (numCourses)){
            return topo;
        }
        return {};
       



        
    }
};