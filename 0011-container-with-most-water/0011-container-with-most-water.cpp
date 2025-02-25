#include<bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        // naive approach
        // for(int i = 0; i< height.size(); i++){
        //     for(int j = i+1; j < height.size(); j++){
        //         int h = min(height[i], height[j]);
        //         int width = j -i;
        //         area = max(area, h*width);
        //     }
        // }
        // return area;

        //using two pointer
        int start = 0, end = height.size()-1, prevArea;
        while(start < end){
            int width = end - start;
            int uchai = min(height[start], height[end]);
            area = max(area, width * uchai);
            // if(prevArea < area){
                if(height[start] < height[end]){
                    start++;
                }else{
                    end--;
                }
            // }
            // int prevArea = area;
        }
        return area;
    }
};