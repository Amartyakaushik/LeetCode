class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> st;
        vector<int> tempArray(size);
        tempArray[size - 1] = 0, st.push(size - 1);
        for(int i = size - 2; i >= 0; i--){
            while(!st.empty() && (temperatures[i] >= temperatures[st.top()])) st.pop();
            if(!st.empty()) tempArray[i] = (st.top() - i);
            else tempArray[i] = 0;
            st.push(i);
        }
        return tempArray;
    }
};