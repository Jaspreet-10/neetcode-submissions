class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxi = 0, index = 0;
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int i = 0 ; i < n ; ++i){
            dp[i][i] = true;
            maxi = 1;
        }
        for(int i = 0 ; i < n-1 ; ++i){
            if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            maxi = 2;
            index = i;
            }
        }
        for(int i = 2 ; i < n ; ++i){
            for(int j = 0 ; j<=n-i ; ++j){
                if(s[j] == s[j+i] && dp[j+1][j+i-1]){
                    dp[j][j+i] = true;
                    maxi = i+1;
                    index = j;
                }
            }
        }
        return (maxi == 0) ? "" : s.substr(index, maxi);
    }
};
