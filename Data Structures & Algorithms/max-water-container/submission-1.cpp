class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1, maxArea = 0;
        while(i<j){
            maxArea = max(maxArea, (j-i)*min(heights[i], heights[j]));
            if(heights[i]>heights[j]) --j;
            else ++i;
        }
        return maxArea;
    }
};
