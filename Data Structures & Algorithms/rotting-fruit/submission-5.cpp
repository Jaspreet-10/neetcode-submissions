class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), steps = 0;
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            steps = q.front().second;
            q.pop();

            int r[4] = {0, 1, 0, -1};
            int c[4] = {1, 0, -1, 0};

            for(int k = 0 ; k < 4 ; ++k){
                int row = r[k] + i;
                int col = c[k] + j;
                if(row>=0 and row<m and col>=0 and col<n 
                    and grid[row][col] == 1){
                        grid[row][col] = -1;
                        q.push({{row, col}, steps+1});
                }
            }
        }
        
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1) return -1;
            }
        }
        return steps;
    }
};
