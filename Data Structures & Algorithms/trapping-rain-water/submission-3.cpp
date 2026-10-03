class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size(), area = 0, maxi = 0;
        vector<int>left(n, 0), right(n, 0);
        for(int i = 0 ; i < n ; ++i){
            if(heights[i]>maxi) maxi = heights[i];
            left[i] = maxi;
        }
        maxi = 0;
        for(int i = n-1 ; i>=0 ; --i){
            if(heights[i]>maxi) maxi = heights[i];
            right[i] = maxi;
        }
        for(int i = 0 ; i < n ; ++i){
            area+= min(left[i], right[i]) - heights[i];
        }
        return area;
    }
};
