class Solution {
    bool isvalid(vector<vector<char>>& board, int r, int c){
        int val = board[r][c];
        board[r][c] = '.';

        for(int i=0;i<9;i++){
            if(board[i][c] == val)return false;
            if(board[r][i] == val)return false;

            if(board[3*(r/3) + i/3][3*(c/3)+i%3] == val)
            return false;
        }
        board[r][c] = val;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j = 0 ; j<9;j++){
                if(board[i][j]!='.' and !isvalid(board,i,j))
                return false;
            }
        }
        return true;
    }
};
