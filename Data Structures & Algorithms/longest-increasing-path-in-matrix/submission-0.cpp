class Solution {
public:
    int findLongestPath(int i, int j, int m, int n, int prev, 
    vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n || matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up =  1 + findLongestPath(i-1, j, m, n, matrix[i][j], matrix, dp);
        int down = 1 + findLongestPath(i+1, j, m, n, matrix[i][j], matrix, dp);
        int right = 1 + findLongestPath(i, j+1, m, n, matrix[i][j], matrix, dp);
        int left = 1 + findLongestPath(i, j-1, m, n, matrix[i][j], matrix, dp);
        return dp[i][j] = max({up,down,right,left});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int maxi = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                maxi = max(maxi, findLongestPath(i, j, m, n, INT_MIN, 
                matrix, dp));
            }
        }
        return maxi;
    }
};
