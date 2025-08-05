class Solution {
public:
    int trap(vector<int>& height) {
        // // choose starting point
        // int start = 0, gap = 0, i =0;
        // for(i < height.size()){
        //     if(height[i] != 0) start = i;
        //     int boundary, minHeight;
        //     for(int j = i; j < height.size(); j++){
        //         if(height[j] >= height[start]) boundary = j;
        //     }
        //     minHeight = (height[i] < height[j]) ? height[i] : height[boundary];
        //     int valuesBwIndices = 0;
        //     for(int k = i + 1; k < boundary; k++) valuesBwIndices += height[k]; 
        //     gap += ((boundary - i - 1) * minHeight) - valuesBwIndices;
        //     i = boundary;
        // }

        // step1 find next boundary ( height[i] >= start)
        // find min height b/w (current ix and boundary)
        // find gap where water can be stored ((total indices in b/w * min height) - sum of values of indices in b/w)
        // again start moving starting point (consider current boundary as starting point for next) and if step 1 not found move index forward
        int gap= 0;
        stack<int> st;
        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && (height[i] > height[st.top()])){
                int top = st.top();
                st.pop();
            

            if(st.empty()) break;
            int distance = i - st.top() - 1;
            int minHeight = min(height[i], height[st.top()]) - height[top] ;
            gap += minHeight * distance;
            }
            st.push(i);
        }
        return gap;
    }
};