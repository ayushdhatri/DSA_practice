class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        int n = intervals.size();
        if(n==0||n==1)
            return intervals;
        vector<pair<int, int>>inter;
        for(int i=0;i<n;i++)
        {
            inter.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(inter.begin(), inter.end());
        stack<pair<int, int>>ans;
        ans.push(inter[0]);
        for(int i=1;i<n;i++)
        {
            pair<int, int>top = ans.top();
            if(inter[i].first<=top.second)// it means i have to merge it
            {
                ans.pop();
                ans.push({top.first, max(inter[i].second, top.second)});
            }
            else
            {
                ans.push(inter[i]);
            }
        }
        vector<vector<int>>fs;
        while(ans.size()!=0)
        {
            pair<int, int>temp = ans.top();
            ans.pop();
            vector<int>temp2;
            temp2.push_back(temp.first);
            temp2.push_back(temp.second);
            fs.push_back(temp2);
        }
        reverse(fs.begin(), fs.end());
        return fs;
        
        
        
        
    }
};