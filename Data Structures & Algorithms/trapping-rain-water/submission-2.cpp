class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n, 0);
        vector<int>right(n, 0);
        int maxLeft = 0, maxRight = 0, ans = 0;
        left[0] = height[0];
        for(int i = 0 ; i < n ; ++i){
            if(height[i]>maxLeft) maxLeft = height[i];
            left[i] = maxLeft; 
        }
        for(int i = n-1 ; i>=0 ; --i){
           if(height[i]>maxRight) maxRight = height[i];
           right[i] = maxRight;
        }
        for(int i = 0 ; i < n ; ++i){
            ans+=min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};
