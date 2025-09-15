class Solution {
    private:
        void check(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& currPath, int index, int remaining){
            if(remaining == 0){
                ans.emplace_back(currPath);
                return;
            }
            if(index >= candidates.size() || remaining < candidates[index]) return;
            //include 
            currPath.push_back(candidates[index]);
            check(ans, candidates, currPath, index + 1, remaining - candidates[index]);
            currPath.pop_back();
            // exclude
            int nextIx = index + 1;
            while(nextIx < candidates.size() && candidates[index] == candidates[nextIx]) {
                nextIx++;
            }
            check(ans, candidates, currPath, nextIx, remaining);
            // // exclude
            // check(ans, candidates, currPath, index+1, remaining);
            // // include
            // currPath.push_back(candidates[index]);
            // check(ans, candidates, currPath, index + 1, remaining - candidates[index]);
            // currPath.pop_back();
        }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currPath;
        sort(candidates.begin(), candidates.end());
        check(ans,candidates, currPath, 0, target);
        // vector<vector<int>> finalAns(ans.begin(), ans.end());
        return ans;
    }
};