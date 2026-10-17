class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]+=1;
        }
        priority_queue<int, vector<int> , greater<int>>pq;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                pq.push(i);
            }
        }
        while(pq.size()!=0){
            int topNode = pq.top();
            pq.pop();
            for(auto x: adj[topNode]){
                indegree[x]--;
                // since we reduce the indegree we must insert into x topnode as anscestor
                ans[x].insert(topNode);
                for(auto ances : ans[topNode]){
                    ans[x].insert(ances);
                }
                if(indegree[x] == 0){
                    pq.push(x);
                }
            }
        }
        vector<vector<int>>fans;
        for(auto x: ans){
            vector<int>temp;
            for(auto y : x){
                temp.push_back(y);
            }
            fans.push_back(temp);

        }
        return fans;
    }
};