class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, left = 0, ans = 0;
        unordered_map<char, int> freq;
        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while((r - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, (r - left + 1));
        }
        return ans;
    }
};