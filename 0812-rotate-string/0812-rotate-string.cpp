class Solution {
public:

    vector<int> computeLPS(string goal){
        int n = goal.size();
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++){
            int j = pi[i - 1];
            while(goal[i] != goal[j] && j > 0){
                j = pi[j -1];
            }
            if(goal[i] == goal[j]){
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }

    bool KMP(string s, string goal){
        int n = s.size(), m = goal.size();
        vector<int> LPS = computeLPS(goal);

        int i = 0, j = 0;
        while(i < n){
            if(s[i] == goal[j]){
                i++, j++;
                if(j == m) return true;
            }else{
                if(j) j = LPS[j -1];
                else i++;
            }
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        
        // // naive approach 
        // for(int i = 0; i < s.size(); i++){
        //     if(s == goal) return true;
        //     char last = s.back();
        //     s.pop_back();
        //     s = last + s;
        // }
        // return false;

        // // alternate approach
        // if(s.size() != goal.size()) return false;
        // return (s + s).find(goal) != string::npos;

        // using KMP
        if(s.size() != goal.size()) return false;
        return KMP(s + s , goal);

    }
};