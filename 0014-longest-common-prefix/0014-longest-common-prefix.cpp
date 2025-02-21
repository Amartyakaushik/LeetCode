class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = "";
        if (strs.size() == 1) {
            return strs[0];
        }
        for (int i = 0; i < strs[0].size(); i++) {
            bool isMatched = false;
            // for(int j = 0; i < strs.size()-1; i++){
            //     if(strs[j][i] == strs[j+1][1]){
            //         isMatched = true;
            //     }
            // }
            int j = 0;
            while (j < strs.size() - 1) {
                if (strs[j][i] == strs[j + 1][i]) {
                    isMatched = true;
                }else {
                    isMatched = false;
                    break;
                }
                j++;
            }
            if (isMatched) {
                temp += strs[j][i];
                // isMatched = false;
            }else{
                break;
            }
        }
        return temp;
    }
};