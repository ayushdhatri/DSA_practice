class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>cost(m+1, vector<int>(n+1,1e9));
        deque<pair<int,pair<int,int>>>dq;
        cost[0][0] = 0;
        dq.push_front({0,{0,0}});
        int drow[] = {0,0,+1,-1};
        int dcol[] = {+1,-1,0,0};
        int ans = 1e9;
        while(dq.size()!=0){
            int currRow = dq.front().second.first;
            int currCol = dq.front().second.second;
            int currCost = dq.front().first;
            dq.pop_front();
            if(currRow == m-1 && currCol == n-1){
                ans = currCost;break;
            }
            int currDir = 1;
            for(int i= 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    if(grid[currRow][currCol] == currDir){
                        if(currCost + 0 < cost[nrow][ncol]){
                            cost[nrow][ncol] = currCost;
                            dq.push_front({currCost + 0,{nrow,ncol}});
                        }
                    }
                    else{
                        if(currCost + 1 < cost[nrow][ncol]){
                            cost[nrow][ncol] = currCost+1;
                            dq.push_back({currCost + 1,{nrow,ncol}});
                        }
                    }
                }
                currDir+=1;
            }
        }
        return ans;

        

        
    }
};