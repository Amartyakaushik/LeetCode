class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int &Area){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) return;
        grid[row][col] = 0;
        Area++;
        dfs(grid, row + 1, col, Area);
        dfs(grid, row - 1, col, Area);
        dfs(grid, row, col + 1, Area);
        dfs(grid, row, col - 1, Area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    int Area = 0;
                    dfs(grid, i, j, Area);
                    maxArea = max(maxArea, Area);
                }
            }
        }
        return maxArea;
    }
};