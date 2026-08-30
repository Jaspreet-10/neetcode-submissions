class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, n = s.size(), index = 0;
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int i = 0 ; i < n ; ++i){
            dp[i][i] = true;
            maxLen = 1;
        }
        for(int i = 0 ; i < n-1 ; ++i){
            if(s[i] == s[i+1]){
            index = i;
            dp[i][i+1] = true;
            maxLen = 2;
            }
        }
        for(int i = 2 ; i < n ; ++i){
            for(int j = 0 ; j <=n-i ; ++j){
                if(s[j] == s[j+i] && dp[j+1][j+i-1]){
                    maxLen = i+1;
                    index = j;
                    dp[j][j+i] = true;
                }
            }
        }
        return maxLen == 0 ? "" : s.substr(index, maxLen);
    }
};
