class Solution {
public:
     void countIslands(int i, int j, int m, int n, vector<vector<int>>& grid, 
     int &counter){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        ++counter;
        countIslands(i+1, j, m, n, grid, counter);
        countIslands(i-1, j, m, n, grid, counter);
        countIslands(i, j+1, m, n, grid, counter);
        countIslands(i, j-1, m, n, grid, counter);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int m = grid.size(), n = grid[0].size(), maxi = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    int counter = 0;
                    countIslands(i, j, m, n, grid, counter);
                    maxi = max(maxi, counter);
                }
            }
        }
        return maxi;   
    }
};
