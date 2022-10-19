class Solution {
public:
     int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>grid(n, vector<int>(m, 0));
        for(int i=0;i<m;i++)
            grid[0][i]=matrix[0][i]-'0';
        for(int row=1;row<n;row++)
        {
            
            for(int col=0;col<m;col++)
            {
                if(matrix[row][col]=='0')
                    grid[row][col]=0;
                else
                    grid[row][col]=grid[row-1][col]+1;
                
            }
                
        }
       int maxans = INT_MIN;
        for(int row=0;row<n;row++)
        {
            vector<int>heights(m);
           for(int col=0;col<m;col++)
           {
               heights[col]=grid[row][col];
            }
            int temp = largestRectangleArea(heights);
            maxans = max(maxans, temp);
        } 
        return maxans;
        
    }
};