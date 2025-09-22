class Solution {
public:
 

    bool palindrome(string s, int startIx, int endIx){
        while(startIx < endIx){
            if(s[startIx++] != s[endIx--])
            return false;
        }
        return true;
    }
    void find(vector<vector<string>>& ans, string s, vector<string>& currPath, int index){
        int strSize = s.length();
        if(index == strSize){
            ans.emplace_back(currPath);
        }

        for(int ix = index; ix < strSize; ix++){
            if(palindrome(s, index, ix)){
                currPath.push_back(s.substr(index, ix - index + 1));
                find(ans, s, currPath, ix+1);
                currPath.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int strSize = s.length();
        vector<string> currPath;
        find(ans, s, currPath, 0);
        return ans;
    }
};