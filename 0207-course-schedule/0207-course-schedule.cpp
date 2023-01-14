class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses, 0);
        vector<int> adj[numCourses];
        int vertex = prerequisites.size();
        for(int i = 0;i<vertex;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++)
        {
            for(auto x: adj[i])
            {
                indegree[x]++;
            }
        }
        for(int i = 0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size()!=0)
        {
            int currvertex = q.front();
            q.pop();
            ans.push_back(currvertex);
            for(auto x: adj[currvertex])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }

        }
        if(ans.size()==numCourses)return true;
        return false;
        
    }
};