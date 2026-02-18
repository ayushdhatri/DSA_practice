class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // IMP observation I did : you should always move, you cannot stop at any point so it is allowed here to visited
        // the cell again, it just that we dont want to stop
        // return -1 only if at particular cell you are not able to move in any direction
        // apply dijkstras move and 4 direction with each node as {time,{currRow, currCol}}
        // if at any movement you hit the bottom cell simply return currTime from there
        // after putting stress more, I got to know that lets say we arrive at particular cell at time t
        // if difference between adjacent cell time and currTime t is even then we need to spend t time more  that to 
        // move to adjacent cell we need to spend t + (difference)
        // if difference is odd then in that case we need to spend t + (difference + 1);
        // we can return -1 only if we are not able to move from zero itself
        // else everywhere we can burn time and can move in all direction and the point when we hit last row, col we return tha time
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1)return -1;
        vector<vector<int>>dist(m+1, vector<int>(n+1, 1e9));
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        >pq;
        pq.push({0,{0,0}});
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(pq.size()!=0){
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            int currTime = pq.top().first;
            if(currRow == m-1 && currCol == n-1)return currTime;
            pq.pop();
            for(int i = 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow>=0 && nrow < m && ncol >=0 && ncol <n){
                    int adjTime = grid[nrow][ncol];
                    if(currTime + 1 >= adjTime){
                        if(currTime + 1 < dist[nrow][ncol]){
                            dist[nrow][ncol] = currTime + 1;
                        pq.push({currTime + 1,{nrow, ncol}});
                        }
                    }
                    else{
                        int diff = adjTime - currTime;
                            
                            if (diff % 2 == 0) {
                                // Even difference: we arrive exactly 1 second after the cell's requirement
                                if(adjTime + 1 < dist[nrow][ncol]){
                                    dist[nrow][ncol] = adjTime + 1;
                                    pq.push({adjTime + 1, {nrow, ncol}});
                                }
                            } else {
                                // Odd difference: we arrive at the exact second of the cell's requirement
                                if(adjTime < dist[nrow][ncol]){
                                    dist[nrow][ncol] = adjTime;
                                    pq.push({adjTime, {nrow, ncol}});
                                }
                            }
                    }
                    
                }
            }




        }
        return -1;


        
    }
};