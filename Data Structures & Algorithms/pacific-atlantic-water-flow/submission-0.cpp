class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};

    void dfs(int row, int col,
             vector<vector<int>>& reachable,
             vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        reachable[row][col] = 1;

        for (int k = 0; k < 4; k++) {
            int newRow = row + dr[k];
            int newCol = col + dc[k];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                !reachable[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col]) {

                dfs(newRow, newCol, reachable, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pacificReachable(rows, vector<int>(cols, 0));
        vector<vector<int>> atlanticReachable(rows, vector<int>(cols, 0));

        // Start DFS from Pacific Ocean borders
        for (int row = 0; row < rows; row++) {
            dfs(row, 0, pacificReachable, heights);
            dfs(row, cols - 1, atlanticReachable, heights);
        }

        // Start DFS from Atlantic Ocean borders
        for (int col = 0; col < cols; col++) {
            dfs(0, col, pacificReachable, heights);
            dfs(rows - 1, col, atlanticReachable, heights);
        }

        vector<vector<int>> answer;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacificReachable[row][col] &&
                    atlanticReachable[row][col]) {
                    answer.push_back({row, col});
                }
            }
        }

        return answer;
    }
};