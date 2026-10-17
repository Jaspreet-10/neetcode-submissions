class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), total = 0;
        vector<int>left(n, 0), right(n, 0);
        int maxi = height[0];
        for(int i = 0 ; i < n ; ++i){
            maxi = max(maxi, height[i]);
            left[i] = maxi;
        }

        maxi = height[n-1];
        for(int i = n-1 ; i>=0 ; --i){
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }

        for(int i = 0 ; i < n ; ++i){
            total+=min(left[i], right[i]) - height[i];
        }
        return total;
    }
};
