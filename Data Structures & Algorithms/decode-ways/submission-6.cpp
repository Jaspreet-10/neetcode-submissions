class Solution {
public:
    int helper(int index, int n, string s, vector<int>&dp){
        if(index>=n) return 1;
        if(dp[index]!=0) return dp[index];

        int oneLetter = 0, twoLetters = 0; 
        if(s[index]!='0'){
            oneLetter = helper(index+1, n, s, dp);
        if(index+1<n and stoi(s.substr(index, 2))<=26)
            twoLetters = helper(index+2, n, s, dp);   
        }
        return dp[index] = oneLetter + twoLetters;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, 0);
        return helper(0, n, s, dp);
    }
};
