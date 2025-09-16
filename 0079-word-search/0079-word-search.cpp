class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int row, int col, int index){
        if(index == word.size()) return true;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) return false;
        
        int temp = board[row][col];
        board[row][col] = '0';
        bool found = (search(board, word, row, col + 1, index + 1) ||    // dfs call for iterating each path
                      search(board, word, row, col - 1, index + 1) ||
                      search(board, word, row + 1, col, index + 1) ||
                      search(board, word, row - 1, col, index + 1));
        board[row][col] = temp;  // backtrack
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(board[r][c] == word[0]){
                    if(search(board, word, r, c, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}; 