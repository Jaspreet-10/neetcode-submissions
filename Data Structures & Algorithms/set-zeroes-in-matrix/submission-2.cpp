class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;  // Indicates whether the first column should be zeroed

        // Step 1: Use first row and first column as markers
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = 0;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Update the matrix in reverse order
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }

            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};
