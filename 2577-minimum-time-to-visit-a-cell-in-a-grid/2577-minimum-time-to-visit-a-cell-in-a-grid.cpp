const int INF = 1e9;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<int>>timeToReach(m, vector<int>(n, INF));
        priority_queue<pair<int, pair<int ,int>>,
        vector<pair<int, pair<int ,int>>>,
        greater<pair<int, pair<int ,int>>>
        >pq;
        timeToReach[0][0] = 0;
        pq.push({0,{0,0}});
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        int minTime = INT_MAX;
        while(pq.size()!=0){
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            int currTimeToReach = pq.top().first;
            pq.pop();
            if(currRow == m-1 && currCol == n-1){
                minTime = currTimeToReach;
                break;
            }
            for(int i = 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow >=0 && nrow < m && ncol>=0 && ncol < n){
                    int newTime;
                    if(currTimeToReach + 1 >= grid[nrow][ncol]){
                       
                        newTime = currTimeToReach + 1;
                    }
                    else{
                        // need to wait and osscilate
                        int timeTake = currTimeToReach;
                        int timeDiff = grid[nrow][ncol] - currTimeToReach;
                        timeTake = timeDiff%2==0 ?grid[nrow][ncol] + 1 : grid[nrow][ncol];
                        newTime = timeTake;
                    }
                    if(newTime < timeToReach[nrow][ncol]){
                        pq.push({newTime, {nrow, ncol}});
                        timeToReach[nrow][ncol] = newTime;
                    }
                }
            }
            
        }
        if(minTime == INT_MAX)return -1;
        return minTime;

        
    }
};