class Solution {
public:
    void countIslands(int i, int j, int m, int n, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        countIslands(i+1, j, m, n, grid);
        countIslands(i-1, j, m, n, grid);
        countIslands(i, j+1, m, n, grid);
        countIslands(i, j-1, m, n, grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), counter = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == '1'){
                    ++counter;
                    countIslands(i, j, m, n, grid);
                }
            }
        }
        return counter;
    }
};
