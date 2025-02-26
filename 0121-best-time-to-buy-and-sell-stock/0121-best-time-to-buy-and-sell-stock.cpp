class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyingPrice = INT_MAX, maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minBuyingPrice);
            if (minBuyingPrice > prices[i])
                minBuyingPrice = prices[i];
        }
        return maxProfit;
    }
};