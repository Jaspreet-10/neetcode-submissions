class Solution {
   public:
    bool wordSearch(int index, int i, int j, int m, int n, 
    vector<vector<char>>& board, string word) {
        if (index == word.size()) return true;
        if (index >= word.size() || i >= m || j >= n || i < 0 || j < 0 || board[i][j] == '.')
            return false;
        if (board[i][j] == word[index]) {
            char ch = board[i][j];
            board[i][j] = '.';
            if (wordSearch(index + 1, i + 1, j, m, n, board, word)) return true;
            if (wordSearch(index + 1, i - 1, j, m, n, board, word)) return true;
            if (wordSearch(index + 1, i, j + 1, m, n, board, word)) return true;
            if (wordSearch(index + 1, i, j - 1, m, n, board, word)) return true;
            board[i][j] = ch;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && wordSearch(0, i, j, m, n, board, word)) 
                    return true;
            }
        }
        return false;
    }
};
