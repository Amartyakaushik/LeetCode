class Solution {
public:
    bool isPalindrom(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return (r == s);
    }
    string longestPalindrome(string s) {
        // string ans; // stores the longest pallindrome
        // int maxLen = 0; // to keep track of length longest palindrome
        // if(s.size() == 1) return s;
        // for(int i = 0; i < s.size()-1; i++){
        //     for(int j = 1; j<=s.size()-i; j++){
        //         string temp = s.substr(i,j);
        //         if(isPalindrom(temp) && temp.size() > maxLen){
        //             ans = temp;
        //             maxLen = ans.size();
        //         }
        //     }
        // }
        // return ans;

        // // another apporach
        //         string ans;
        //         for(int i = 0; i < s.size(); i++){
        //             int end = s.size()-i;
        //             string temp = s.substr(i, end);
        //             while(end > 0 && end > ans.size()){
        //                 if(isPalindrom(temp)) ans = temp;
        //                 end--;
        //                 temp = s.substr(i, end);
        //             }
        //         }
        //         return ans;

        // using DP to store previous result to compare next longest palindrome
        int startIndex = 0, maxLength = 1;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true; // str of len 1 is always a palindrom
            if (s[i] == s[i + 1] && i <= n - 1) { // str of len 2 is a palindrom
                                                  // if both char are same
                dp[i][i + 1] = true;
                startIndex = i;
                maxLength = 2;
            }
        }

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (length > maxLength) {
                        maxLength = length;
                        startIndex = i;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLength);
    }
};