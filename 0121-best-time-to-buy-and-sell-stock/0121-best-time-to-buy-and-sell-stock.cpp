class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // unordered_map<int, int> maxProfit;
        // int maxP = 0;
        // int startIx = 0;
        // while(startIx < prices.size() - 1){
        //     for(int i = startIx + 1; i < prices.size(); i++){
        //     // maxProfit[prices[i]] = max(maxProfit[prices[i]], (prices[startIx] - prices[i]));
        //     maxP = max(maxP, (prices[i] - prices[startIx]));
        //     }
        //     startIx++;
        // }
        // return maxP;
        int minBuyingPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            maxProfit = max(maxProfit, (prices[i] - minBuyingPrice));
            if(minBuyingPrice > prices[i]) minBuyingPrice = prices[i];
        }
        return maxProfit;

    }
};