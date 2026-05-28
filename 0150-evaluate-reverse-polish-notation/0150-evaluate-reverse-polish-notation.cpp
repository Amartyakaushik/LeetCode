class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();
        for(int i = 0; i < size; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int oprd2 = st.top();
                st.pop();
                int oprd1 = st.top();
                st.pop();
                int newVal;
                if(tokens[i] == "+") newVal = oprd1 + oprd2;
                else if(tokens[i] == "-") newVal = oprd1 - oprd2;
                else if(tokens[i] == "*") newVal = oprd1 * oprd2;
                else newVal = oprd1 / oprd2;
                st.push(newVal);
            }else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};