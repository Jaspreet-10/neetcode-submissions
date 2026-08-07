class Solution {
public:
    int decodeWays(int index, int n, string s, vector<int>&dp){
        if(index>=n) return 1;
        if(dp[index]!=-1) return dp[index];
        int c1 = 0, c2 = 0;
        if(s[index]!='0'){
            c1 = decodeWays(index+1, n, s, dp);
        if(index+1<n && stoi(s.substr(index, 2))<=26)
            c2 = decodeWays(index+2, n, s, dp);
        }
        return dp[index] = c1+c2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return decodeWays(0, n, s, dp);
    }
};
