class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
      
        vector<int> dp(n, -1);
      
        auto dfs = [&](this auto&& dfs, int currentStep) -> int {
            if (currentStep >= n) {
                return 0;
            }
            if (dp[currentStep] != -1) {
                return dp[currentStep];
            }
          
            dp[currentStep] = cost[currentStep] + 
                              min(dfs(currentStep + 1), dfs(currentStep + 2));
          
            return dp[currentStep];
        };
    
        return min(dfs(0), dfs(1));
    }
};