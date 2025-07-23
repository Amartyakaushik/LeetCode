class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> targetCombinations;
        // for(int x = 0; x < candidates.size(); x++){
        //     // 
        //     if(target % x == 0){
        //         vector<int> combination;
        //         for(int i = 0; i < (target / x); i++){
        //             combination.push_back(x);
        //         }
        //         targetCombinations.push_back(combination);
        //     }
            
        // }

        sort(candidates.begin(), candidates.end());
        vector<int> currComb;
        function<void(int, int)> dfs = [&](int ix, int remaining) {
            if(remaining == 0){
                targetCombinations.emplace_back(currComb);
                return;
            }
            if(ix >= candidates.size() || remaining < candidates[ix])
                return;
            dfs(ix + 1, remaining);
            currComb.push_back(candidates[ix]);
            dfs(ix, remaining - candidates[ix]);
            currComb.pop_back();
        };
        dfs(0, target);
        return targetCombinations;
    }
};