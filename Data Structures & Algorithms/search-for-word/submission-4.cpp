class Solution {
public:
    bool helper(int i, int j, int k, int m, int n, vector<vector<char>>& board,
    string &word){
        if(k == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || k>=word.size() || word[k]!=board[i][j]) 
            return false;
        char temp = board[i][j];
        board[i][j] = '.';
        bool d = helper(i+1, j, k+1, m, n, board, word);
        bool u = helper(i-1, j, k+1, m, n, board, word);
        bool r = helper(i, j+1, k+1, m, n, board, word);
        bool l = helper(i, j-1, k+1, m, n, board, word);
        board[i][j] = temp;
        return d or u or r or l;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
            if(board[i][j] == word[0]){
                if(helper(i, j, 0, m, n, board, word)) return true;
                }
            }
        }
        return false;
    }
};
