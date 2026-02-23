class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<vector<int>>graph(numCourses);
        for(int i = 0;i<m;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
        }
        vector<int>indegree(numCourses, 0);
        for(int i = 0;i<numCourses;i++){
            for(int j = 0;j<graph[i].size();j++){
                indegree[graph[i][j]]+=1;
            }
        }
        queue<int>q;
        vector<int>topo;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(q.size()!= 0){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto x: graph[node]){
                indegree[x]--;
                if(indegree[x] == 0)q.push(x);
            }
        }
        if(topo.size() == numCourses)return topo;
        return {};
    }
};