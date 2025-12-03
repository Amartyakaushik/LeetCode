class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 0; i <= n; i++){
            // int temp = -(~i );
            // ans.push_back(temp);
            ans[i] = ans[i / 2] + (i % 2);  

        }
        return ans;
    }
};