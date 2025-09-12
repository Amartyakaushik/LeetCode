class Solution {
    private:
        void check(vector<int> candidates, int remaining, vector<int> currPath, int index, vector<vector<int>>& ans){
            if(remaining == 0){
                ans.emplace_back(currPath);
                return;
            }
            if(index >= candidates.size() || remaining < candidates[index]) return;

            // exclude
            check(candidates, remaining, currPath, index+1, ans);
            currPath.push_back(candidates[index]);
            check(candidates, remaining - candidates[index], currPath, index, ans);
            currPath.pop_back();
            
        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> currPath;
        check(candidates, target, currPath, 0, ans);
        return ans;

    }
};