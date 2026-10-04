class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), steps = 0;
        queue<pair<int, pair<int, int>>>q;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            steps = q.front().first;
            q.pop();
            int row[4] = {-1, 0, 1, 0};
            int col[4] = {0, 1, 0, -1};
            for(int i = 0 ; i < 4 ; ++i){
                int rc = r + row[i];
                int cc = c + col[i];
                if(rc<m and cc<n and rc>=0 and cc>=0 
                and grid[rc][cc] == 1){
                    grid[rc][cc] = 0;
                    q.push({steps+1, {rc, cc}});
                }
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return steps;
    }
};
