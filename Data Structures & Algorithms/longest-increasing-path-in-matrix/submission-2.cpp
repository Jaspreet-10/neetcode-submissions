class Solution {
public:
    int findUniquePaths(int i, int j, int m, int n, int prev, 
    vector<vector<int>>& matrix, map<pair<pair<int, int>, int>, int>&dp){
        if(i<0 || j<0 || i >= m || j>=n || matrix[i][j]<prev) return 0;
        if(dp.find({{i, j}, prev+1})!=dp.end()) return dp[{{i, j},prev+1}];
        int down = 0, up = 0, right = 0, left = 0;
        if(prev == -1 || matrix[i][j]>prev){ 
        down = 1 + findUniquePaths(i+1, j, m, n, matrix[i][j], matrix, dp);
        right = 1 + findUniquePaths(i, j+1, m, n, matrix[i][j], matrix, dp);
        up = 1 + findUniquePaths(i-1, j, m, n, matrix[i][j], matrix, dp);
        left = 1 + findUniquePaths(i, j-1, m, n, matrix[i][j], matrix, dp);
        }
        return dp[{{i, j},prev+1}] = max(down, max(right, max(left, up)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), prev = -1, maxi = 0;
        map<pair<pair<int, int>, int>, int>dp;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                maxi = max(maxi, findUniquePaths(i, j, m, n, prev, matrix, dp));
            }
        }
        return maxi;
    }
};
