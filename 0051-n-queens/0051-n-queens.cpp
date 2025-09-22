class Solution {
public:
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;
    void backTrack(vector<vector<string>>& ans, int size, int row, vector<int>& queen){
        if(row == size){
            vector<string> board(size, string(size, '.'));
            for(int r = 0; r < size; r++){
                board[r] [queen[r]] = 'Q';
            }
            ans.emplace_back(board);
        }

        for(int col = 0; col < size; col++){
            if(cols[col] || diag1[row + col] || diag2[row - col + size - 1]) continue;
            queen[row] = col;
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + size - 1] = true;
            backTrack(ans, size, row + 1, queen);
            
            queen[row] = -1;
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + size - 1] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queen(n, -1);
        cols = vector<bool>(n, false);
        diag1 = vector<bool>(n, false);
        diag2 = vector<bool>(n, false);
        backTrack(ans, n, 0, queen);
        return ans;
    }
};