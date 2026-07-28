class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>>q;
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[i].size() ; ++j){
            if(grid[i][j] == 0){
                q.push({{i,j}, 0});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            int row[4] = {1,0,-1,0};
            int col[4] = {0,-1,0,1};
            for(int i = 0 ; i < 4 ; ++i){
                int rc = row[i] + r;
                int cc = col[i] + c;
                if(rc>=0 && cc>=0 && rc<grid.size() && 
                cc<grid[0].size() && grid[rc][cc] == 2147483647){
                    q.push({{rc, cc}, steps+1});
                    grid[rc][cc] = steps+1;
                }
            }
        }
        return;
    }
};
