class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int rowSize = grid.size(), colSize = grid[0].size(), targetColor = grid[row][col];
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        vector<vector<bool>> isBorder(rowSize, vector<bool>(colSize, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        q.push({row, col});
        visited[row][col] = true;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(auto &dir : directions){
                int nextRow = r + dir.first;
                int nextCol = c + dir.second;
                if(nextRow >= 0 && nextRow < rowSize && nextCol >= 0 && nextCol < colSize && grid[nextRow][nextCol] == targetColor && !visited[nextRow][nextCol]){
                    visited[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }else if(!isBorder[r][c] && (nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize || grid[nextRow][nextCol] != targetColor)) isBorder[r][c] = true;
            }
        }

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                if(isBorder[i][j]) grid[i][j] = color;
            }
        }
        return grid;
    }
};