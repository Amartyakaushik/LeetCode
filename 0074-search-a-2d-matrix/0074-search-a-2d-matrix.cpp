class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool present = false;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(target == matrix[i][j]) present = true;
            }
        }
        if(present) return true;
        return false;
    }
};