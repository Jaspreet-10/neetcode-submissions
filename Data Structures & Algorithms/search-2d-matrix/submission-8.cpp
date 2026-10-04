class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size()-1, col = matrix[0].size()-1,
        row = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(target>=matrix[mid][0] and target<=matrix[mid][col]){
                row = mid;
                break;
            }
            else if(target>matrix[mid][col])
                low = mid+1;
            else high = mid-1;
        }
        low = 0, high = col;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid]>target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
