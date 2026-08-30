class Solution {
public:
    int subs(int i, int j, int m, int n, string s, string t, vector<vector<int>>&dp){
        if(j>=n) return 1;
        if(i>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int consider = 0;
        if(s[i] == t[j]){
            consider = subs(i+1, j+1, m, n, s, t, dp);
        }
        int notConsider = subs(i+1, j, m, n, s, t, dp);
        return dp[i][j] = consider + notConsider;
    }
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return subs(0, 0, m, n, s, t, dp);
    }
};
