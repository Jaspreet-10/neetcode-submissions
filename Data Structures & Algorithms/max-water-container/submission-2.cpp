class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1, maxi = 0;
        while(i<j){
            int prod = min(heights[i], heights[j]) * (j-i);
            maxi = max(maxi, prod);
            if(heights[i]>heights[j])--j;
            else ++i;
        }
        return maxi;
    }
};
