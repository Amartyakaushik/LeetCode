class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0, j = height.size()-1, area = 0;
        while(i < height.size()-1 && j >= 0){
            int minHeight = min(height[i], height[j]);
            area = max(area, minHeight * (j -i));
            if(height[i] < height[j]) 
                i++;
            else
                j--;
        }
        return area;
    }
};