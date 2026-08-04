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
            int r = q.front().first.first;
            int c = q.front().first.second;
            int counter = q.front().second;
            q.pop();
            grid[r][c] = counter;
            int row[4] = {1,0,-1,0};
            int col[4] = {0,-1,0,1};
            for(int i = 0 ; i < 4 ; ++i){
                int rc = row[i] + r;
                int cc = col[i] + c;
                if(rc>=0 && cc>=0 && rc<m && cc<n && grid[rc][cc]==2147483647){
                    q.push({{rc, cc}, counter+1});
                    grid[rc][cc] = -1;
                }
            }
        }
        return;
    }
};
