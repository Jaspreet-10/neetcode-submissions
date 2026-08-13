class Solution {
public:
    int findRow(vector<vector<int>>&matrix, int target){
        int left = 0, right = matrix.size()-1, col = matrix[0].size()-1, row = 0;
        while(left<=right){
            int mid = (left + right)/2;
            if(matrix[mid][0]<=target and matrix[mid][col] >= target){
                return mid;
            }
            else if(matrix[mid][col] > target) --right;
            else ++left;
        }
        return row;
    }
    bool findTarget(vector<vector<int>>& matrix, int target, int row){
        int left = 0, right = matrix[0].size()-1;
        while(left<=right){
            int mid = (left + right)/2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid]>target) --right;
            else ++left;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        cout<<row<<"\n";
        return findTarget(matrix, target, row);
    }
};
