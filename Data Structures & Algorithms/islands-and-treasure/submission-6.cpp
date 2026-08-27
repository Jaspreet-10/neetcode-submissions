class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 0)
                    q.push({{i, j}, 0});
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int count = q.front().second;
            q.pop();
            int rc[4] = {-1, 0, 1, 0};
            int cc[4] = {0, 1, 0, -1};
            for(int i = 0 ; i < 4 ; ++i){
                int newRow = r + rc[i];
                int newCol = c + cc[i];
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && 
                grid[newRow][newCol] == 2147483647){
                    grid[newRow][newCol] = count+1;
                    q.push({{newRow, newCol}, count+1});
                }
            }
        }
        return ;
    }
};
