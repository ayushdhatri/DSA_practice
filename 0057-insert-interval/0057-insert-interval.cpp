class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>>ans;
        while(i < n){
            if(intervals[i][1] < newInterval[0]){
                // if current interval end is less than start point of new Interval
                ans.push_back(intervals[i]);
                i++;
            }
            else break;
        }

        // phase 2

        while(i < n && intervals[i][0] <= newInterval[1]){
            // it overlap
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
    }
};