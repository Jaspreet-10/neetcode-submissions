class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>>q;
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 0) q.push({{i, j}, 0});
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            count = q.front().second;
            q.pop();
            int r[4] = {0, 1, 0, -1};
            int c[4] = {1, 0, -1, 0};
            for(int k = 0 ; k < 4 ; ++k){
                int rc = r[k] + i;
                int cc = c[k] + j;
                if(rc>=0 and rc<m and cc>=0 and cc<n and grid[rc][cc] == 2147483647){
                    grid[rc][cc] = count+1;
                    q.push({{rc, cc}, count+1});
                }
            }
        }
        return;
    }
};
