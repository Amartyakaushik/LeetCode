class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;
        for(char c : s){
            if(c == '('){
                count++;
            }else if(c== ')'){
                // return -1;
                count--;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};