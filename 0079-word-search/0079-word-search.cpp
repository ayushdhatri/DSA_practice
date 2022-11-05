class Solution {
public:
    bool wordexist(int row, int col, vector<vector<char>>&board, string word, string asf, vector<vector<bool>>&visited, int index)
    {
        if(asf==word)
            return true;    
        if(col>=board[0].size()||col<0||row<0||row>=board.size()||visited[row][col]==true)
            return false;  
        if(board[row][col]!=word[index])
            return false;
        visited[row][col]=true;
        bool right = wordexist(row,col+1, board, word, asf+board[row][col],visited, index+1);
        bool left = wordexist(row, col-1, board, word, asf+board[row][col], visited, index+1);
        bool up = wordexist(row-1, col, board, word, asf+board[row][col], visited, index+1);
        bool down = wordexist(row+1, col, board, word, asf+board[row][col], visited, index+1);
        visited[row][col]=false;
        return right||left||up||down;
          


    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int row= board.size();
        int col = board[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for(int i=0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                string asf="";
                bool temp = wordexist(i, j, board, word, asf, visited,0);
                ans = ans||temp;
                if(ans==true)
                    break;
                }
            }
        }
        return ans;


        
    }
};