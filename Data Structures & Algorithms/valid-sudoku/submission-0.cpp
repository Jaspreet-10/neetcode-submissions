class Solution {
public:
    bool isValidBox(int cr, int cc, vector<vector<char>>&board){
        int startRowIndex = (cr/3)*3;
        int startColIndex = (cc/3)*3;
        for(int j = startRowIndex ; j <=startRowIndex+2; ++j){
            for(int k = startColIndex ; k<=startColIndex+2;++k){
                if(board[j][k] == board[cr][cc] and cr!=j and cc!=k){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkCol(int cr, int cc, vector<vector<char>>&board){
        int j = 0;
        while(j<9){
            if(board[cr][j]==board[cr][cc] && j!=cc) return false;
            ++j;
        }
        return true;
    }

    bool checkRow(int cr, int cc, vector<vector<char>>&board){
        int i = 0;
        while(i<9){
            if(board[i][cc]==board[cr][cc] && i!=cr) return false;
            ++i;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j]!='.'){
                    if((checkRow(i, j, board)) &&
                       (checkCol(i, j, board)) &&
                       (isValidBox(i, j, board))
                    ) continue;
                    else return false;
                }
            }
        }
        return true;
    }
};
