class Solution {
public:
    int helper(int i, int j, int m, int n, string&s1, string &s2,
     vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int consider = 0;
        if(s1[i] == s2[j]){
            consider = 1 + helper(i+1, j+1, m, n, s1, s2, dp);
        }
        int notConsider = max(helper(i+1, j, m, n, s1, s2, dp), 
        helper(i, j+1, m, n, s1, s2, dp));
        return dp[i][j] = max(consider, notConsider);
     }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, text1, text2, dp);   
    }
};
