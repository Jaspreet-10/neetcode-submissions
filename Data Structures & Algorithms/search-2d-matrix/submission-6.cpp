class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int target, int m, int n){
        int low = 0, high = m;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid][0]<=target && matrix[mid][n]>=target) return mid;
            if(matrix[mid][n]>target) high = mid-1;
            else low = mid+1;
        }
        return 0;
    }
    bool findTarget(vector<vector<int>>& matrix, int target, int m, int n, int row){
        int low = 0, high = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid]>target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1, n = matrix[0].size()-1;
        int row = findRow(matrix, target, m, n);
        return findTarget(matrix, target, m, n, row);
    }
};
