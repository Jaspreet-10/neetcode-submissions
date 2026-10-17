class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 0) q.push({{i, j}, 0});
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            int r[4] = {0, 1, 0, -1};
            int c[4] = {1, 0, -1, 0};

            for(int k = 0 ; k < 4 ; ++k){
                int row = r[k] + i;
                int col = c[k] + j;
                if(row>=0 and row<m and col>=0 and col<n 
                    and grid[row][col] == 2147483647){
                        grid[row][col] = steps+1;
                        q.push({{row, col}, steps+1});
                }
            }
        }
        return ;
    }
};
