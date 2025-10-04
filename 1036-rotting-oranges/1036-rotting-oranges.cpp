class Solution {
public:
    void updateRotten(vector<vector<int>>& grid,  queue<pair<int,int>> &q, int &count, int &fresh){
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int row = grid.size(), col = grid[0].size();
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto[r, c] = q.front();
                q.pop();
                for(auto &[dirRow, dirCol] : directions){
                int newRow = dirRow + r, newCol = dirCol + c;
                if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                    fresh--;
                    q.push({newRow, newCol});
                }
            }
                
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = -1, row = grid.size(), col = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2 ){
                    q.push({i, j});
                }else if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        updateRotten(grid, q, minutes, fresh);
        return (fresh == 0) ? minutes : -1;
    }
};