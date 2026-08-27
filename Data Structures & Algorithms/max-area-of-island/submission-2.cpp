class Solution {
public:
    int countIsland(int i, int j, int m, int n, vector<vector<int>>&grid,
        int&count){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        ++count;
        int up = countIsland(i-1, j, m, n, grid, count);
        int down = countIsland(i+1, j, m, n, grid, count);
        int left = countIsland(i, j-1, m, n, grid, count);
        int right = countIsland(i, j+1, m, n, grid, count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxCount = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    int count = 0;
                    maxCount = max(maxCount, countIsland(i, j, m, n, grid, count));
                }
            }
        }
        return maxCount;
    }
};
