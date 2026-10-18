class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int col = nums[0].size()-1, row = 0;

        while(low<=high){
            int mid = (low + high)/2;

            if(target>=nums[mid][0] and target<=nums[mid][col]){
                row = mid;
                break;
            }

            else if(target<nums[mid][col]) high = mid-1;

            else low = mid+1;
        }

        low = 0, high = col;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[row][mid] == target) return true;

            else if(nums[row][mid]>target) high = mid-1;

            else low = mid+1;
        }

        return false;
    }
};
