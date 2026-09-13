class Solution {
public:
    int findLCS(int i, int j, int m, int n, string s1, string s2, 
        vector<vector<int>>&dp){
            if(i>=m || j>=n) return 0;
            if(dp[i][j]!=0) return dp[i][j];
            int match = 0, notAMatch = 0;
            if(s1[i] == s2[j]){
               match = 1+findLCS(i+1, j+1, m, n, s1, s2, dp);
            }else{
                notAMatch = max(findLCS(i+1, j, m, n, s1, s2, dp), 
                findLCS(i, j+1, m, n, s1, s2, dp));
            }
            return dp[i][j] = max(match, notAMatch);
        }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        return findLCS(0, 0, m, n, text1, text2, dp);
    }
};
