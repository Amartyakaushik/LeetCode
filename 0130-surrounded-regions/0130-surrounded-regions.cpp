class Solution {
public:
    
    void dfs(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &visited){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == 'X' || visited[row][col]) return;
        visited[row][col] = true;
        dfs(board, row + 1, col, visited);
        dfs(board, row - 1, col, visited);
        dfs(board, row, col + 1, visited);
        dfs(board, row, col - 1, visited);

    }
    void solve(vector<vector<char>>& board) {
        bool touched = false;
        int rowSize = board.size(), colSize = board[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
  

        for(int row = 0; row < rowSize; row++){
            if(!visited[row][0] && board[row][0] == 'O'){
                cout<<"checking at"<<row<<" "<< 0<<endl;
                dfs(board, row, 0, visited);
            }
            if(!visited[row][board[0].size() - 1] && board[row][board[0].size() - 1] == 'O'){
                cout<<"checking at"<<row<<" "<< board[0].size() - 1<<endl;
                dfs(board, row, board[0].size() - 1, visited);
            }
        }
        for(int col = 0; col < colSize; col++){
            if(!visited[0][col] && board[0][col] == 'O') dfs(board, 0, col, visited);
            if(!visited[board.size() - 1][col] && board[board.size() - 1][col] == 'O') dfs(board, board.size() - 1, col, visited);
        }
        for(int row = 1; row < rowSize-1; row++){
            for(int col = 1; col < colSize-1; col++){
                if((!visited[row][col]) && board[row][col] == 'O') board[row][col] = 'X';
            }
        }
    }
};