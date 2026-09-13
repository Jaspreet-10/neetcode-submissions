class Solution {
public:
    int decodeWays(int index, int n, string s, vector<int>&dp){
        if(index==n) return 1;
        if(index>n) return 0;
        if(dp[index]!=0) return dp[index];
          int twoConsider = 0;
          int oneConsider = 0;
        if(s[index]!='0'){
            oneConsider = decodeWays(index+1, n, s, dp);
            if(index+1 && stoi(s.substr(index, 2))<=26){
                twoConsider = decodeWays(index+2, n, s, dp);
            }
        }
        return dp[index] = oneConsider + twoConsider;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, 0);
        return decodeWays(0, n, s, dp);
    }
};
