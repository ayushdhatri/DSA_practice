class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>ans;
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        vector<int>indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto x: adj[i])
            {
                indegree[x]++;
            }

        }
        for(int i = 0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(q.size()!=0)
        {
            int currnode = q.front();
            q.pop();
            ans.push_back(currnode);
            for(auto x: adj[currnode])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);

            }
        }
        if(ans.size()==numCourses)return ans;
        vector<int>temp;
        return temp;

        
    }
};