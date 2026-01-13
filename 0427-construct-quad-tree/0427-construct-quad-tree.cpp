class Solution {
public:
    bool isUniform(int sr, int er, int sc, int ec, vector<vector<int>>& grid) {
        int first = grid[sr][sc];
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if (grid[i][j] != first) return false;
            }
        }
        return true;
    }

    Node* constructTree(int sr, int er, int sc, int ec, vector<vector<int>>& grid) {
        // base: uniform area => leaf
        if (isUniform(sr, er, sc, ec, grid)) {
            return new Node(grid[sr][sc] == 1, true);
        }

        int midRow = (sr + er) / 2;
        int midCol = (sc + ec) / 2;

        Node* topLeft     = constructTree(sr, midRow, sc, midCol, grid);
        Node* topRight    = constructTree(sr, midRow, midCol + 1, ec, grid);
        Node* bottomLeft  = constructTree(midRow + 1, er, sc, midCol, grid);
        Node* bottomRight = constructTree(midRow + 1, er, midCol + 1, ec, grid);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructTree(0, n - 1, 0, n - 1, grid);
    }
};