class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), maxLeft = 0, maxRight = 0, total = 0;
        vector<int>left(n, 0), right(n, 0);
        for(int i = 0 ; i < n ; ++i){
            if(height[i]>maxLeft) maxLeft = height[i];
            left[i] = maxLeft;
        }
        for(int i = n-1 ; i >= 0 ; --i){
            if(height[i]>maxRight) maxRight = height[i];
            right[i] = maxRight;
        }
        for(int i = 0 ; i < n ; ++i){
            total+=min(left[i], right[i]) - height[i];
        }
        return total;
    }
};
