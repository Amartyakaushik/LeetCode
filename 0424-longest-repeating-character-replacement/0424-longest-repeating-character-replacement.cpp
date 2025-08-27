class Solution {
public:
    int characterReplacement(string s, int k) {
        // int maxLen = 1, maxS = 1, changeCount = k, startix = 0, count = 0;
        // for(int i = 1; i < s.size(); i++){
        //     if(s[i] == s[startix]){
        //         maxLen++;
        //     }else{
        //         if(count == 0){
        //             startix = i, count++;
        //         }
        //         if((--changeCount) >= 0){
        //             maxLen++;
        //         }else{
        //             maxS = max(maxLen, maxS);
        //             i = startix, maxLen = 1, count = 0, changeCount = k;
        //             // break;
        //         }
                
        //     }
        //     maxS = max(maxLen, maxS);
        // }

        unordered_map<char, int> count;
        int maxCharCount = 0, left = 0, r = 0;
        for(r = 0; r < s.size(); r++){
            count[s[r]]++;
            maxCharCount = max(maxCharCount, count[s[r]]);
            // check if window size is exceeding the lenght according to the conditions
            if((r - left + 1 ) - maxCharCount > k){
                count[s[left]]--;
                left++;
            }
        }
        return r - left;
    }
};