class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        // Step 1: build 2D prefix sum
        vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= cols; j++)
                prefix[i][j] = matrix[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];

        // Step 2: try all combinations of (x1,y1) -> (x2,y2)
        int count = 0;
        for (int x1 = 1; x1 <= rows; x1++) {
            for (int y1 = 1; y1 <= cols; y1++) {
                for (int x2 = x1; x2 <= rows; x2++) {
                    for (int y2 = y1; y2 <= cols; y2++) {

                        // O(1) submatrix sum using prefix array
                        int sum = prefix[x2][y2]
                                - prefix[x1-1][y2]
                                - prefix[x2][y1-1]
                                + prefix[x1-1][y1-1];

                        if (sum == target)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
