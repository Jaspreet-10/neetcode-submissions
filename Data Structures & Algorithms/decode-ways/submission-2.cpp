class Solution {
public:
    int decodeString(int index, int n, vector<int>&dp, string s){
        if(index == n) return 1; 
        if(index>=n) return 0;
        if(dp[index]!=0) return dp[index];
        int c1 = 0, c2 = 0;
        if(s[index]!='0'){
        c1 = decodeString(index+1, n, dp, s);
        if(index + 1 < n && stoi(s.substr(index, 2))<=26)
        c2 = decodeString(index+2, n, dp, s);
        }
        return dp[index] = c1 + c2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, 0);
        return decodeString(0, n, dp, s);
    }
};
