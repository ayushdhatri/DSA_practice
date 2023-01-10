//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void bfs(int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&grid,set<vector<pair<int, int>>>&shape)
  
  {
      queue<pair<int, int>>q;
      q.push({row, col});
      int drow[]={-1, 0, +1, 0};
      int dcol[]={0, +1, 0, -1};
      vector<pair<int, int>>tempshape;
      tempshape.push_back({0,0});
      while(q.size()!=0)
      {
          int prow = q.front().first;
          int pcol = q.front().second;
          q.pop();
          // traverse in all four direction
          for(int d = 0;d<4;d++)
          {
              int nrow = prow+drow[d];
              int ncol = pcol+dcol[d];
              if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&visited[nrow][ncol]==false&&grid[nrow][ncol]==1)
              {
                  visited[nrow][ncol]=true;
                  pair<int, int>temp;
                  int a = nrow-row;
                  int b = ncol-col;
                  temp.first = a;
                  temp.second = b;
                  tempshape.push_back(temp);
                  q.push({nrow, ncol});
              }
          }
      }
      shape.insert(tempshape);
      
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m , false));
        set<vector<pair<int, int>>>shape;
        for(int i = 0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                if(visited[i][j]==false&&grid[i][j]==1)
                {
                    visited[i][j]=true;
                    bfs(i, j, visited, grid,shape);
                }
            }
        }
        return shape.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends