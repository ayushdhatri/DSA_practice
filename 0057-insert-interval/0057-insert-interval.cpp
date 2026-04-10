class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            // handle it and return from here
        }
        vector<pair<int,int>>arr;
        for(int i = 0;i<intervals.size();i++){
            arr.push_back({intervals[i][0], intervals[i][1]});
        }
        arr.push_back({newInterval[0], newInterval[1]});
        sort(arr.begin(), arr.end());
        int prev_index = 0;
        int curr_index = 1;
        vector<vector<int>>ans;
        while(curr_index < arr.size()){
            int prev_start = arr[prev_index].first;
            int prev_end = arr[prev_index].second;
            int curr_start = arr[curr_index].first;
            int curr_end = arr[curr_index].second;
            if(curr_start <= prev_end){
                arr[prev_index].second = max(curr_end, prev_end);
            }
            else{
                ans.push_back({arr[prev_index].first, arr[prev_index].second});
                prev_index = curr_index;

            }
            curr_index+=1;
        }
        ans.push_back({arr[prev_index].first, arr[prev_index].second});

        return ans;
        
    }
};