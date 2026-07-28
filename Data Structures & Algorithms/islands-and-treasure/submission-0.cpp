class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>>q;
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[i].size() ; ++j){
                if(grid[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            int rowC[4] = {0,-1,0,1};
            int colC[4] = {-1,0,1,0};
            for(int i = 0 ; i < 4 ; ++i){
                int r = row+rowC[i];
                int c = col+colC[i];
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size()
            and grid[r][c] == 2147483647){
                grid[r][c] = steps+1;
                q.push({steps+1, {r,c}});
            }
            }
        }
        return;
    }
};
