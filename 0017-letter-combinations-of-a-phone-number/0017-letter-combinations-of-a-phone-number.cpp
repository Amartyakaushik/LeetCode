class Solution {
public:
    void find(string& digits, vector<string>& ans, string& curr, unordered_map<char, string> hM, int index){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        for(char c : hM[digits[index]]){
            curr.push_back(c);
            find(digits, ans, curr, hM, index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"}
        };

        string curr;
        vector<string> ans;
        find(digits, ans, curr, phoneMap, 0);
        return ans;

    }
};