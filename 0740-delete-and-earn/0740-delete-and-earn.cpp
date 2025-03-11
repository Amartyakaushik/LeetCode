class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        // Compute total points for each number
        for (int num : nums) {
            points[num] += num;
        }

        // Apply house robber approach
        int prev1 = 0, prev2 = 0;
        for (int i = 0; i <= maxVal; i++) {
            int curr = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};