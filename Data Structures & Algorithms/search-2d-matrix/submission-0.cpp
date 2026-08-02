class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size(), row = 0;
        int low = 0, high = matrix.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                row = mid;
                break;
            }
            else if(matrix[mid][m-1]>=target)
                high = mid-1;
            else 
                low = mid+1;
        }
        low = 0, high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid]>=target)
                high = mid-1;
            else 
                low = mid+1;
        }
        return false;
    }
};
