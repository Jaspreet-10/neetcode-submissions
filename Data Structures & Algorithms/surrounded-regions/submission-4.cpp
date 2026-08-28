class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), count = 0;
        queue<pair<int, int>>q;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O'){
                    board[i][j] = '1';
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int rc[4] = {-1, 0, 1, 0};
            int cc[4] = {0, 1, 0, -1};
            for(int i = 0 ; i < 4 ; ++i){
                int newRow = r + rc[i];
                int newCol = c + cc[i];
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && 
                board[newRow][newCol] == 'O'){
                    board[newRow][newCol] = '1';
                    q.push({newRow, newCol});
                }
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return ;
    }
};
