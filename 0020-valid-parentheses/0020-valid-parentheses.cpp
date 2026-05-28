class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        if(size % 2 != 0) return false;
        for(int i = 0; i < size; i++){
            if(s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
            else if(s[i] == '}' && !st.empty() && st.top() == '{') st.pop();
            else if(s[i] == ']' && !st.empty() && st.top() == '[') st.pop();
            else st.push(s[i]);
        }
        if(st.size() == 0) return true;
        return false;
    }
};