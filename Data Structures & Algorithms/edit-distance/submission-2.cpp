class Solution {
public:
    int minops(int i,int j,string &s1,string &s2,int m,int n,vector<vector<int>>&dp){
        if(j>=n)
            return m-i;
        if(i>=m)
            return n-j;
        int ans = 100000;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i] == s2[j])
           ans = minops(i+1,j+1,s1,s2,m,n,dp);
        else{
            int insert = 1 + minops(i,j+1,s1,s2,m,n,dp);
            int deletion = 1 + minops(i+1,j,s1,s2,m,n,dp);
            int replace = 1 + minops(i+1,j+1,s1,s2,m,n,dp);
            ans =  min({insert,deletion,replace});
        }
        dp[i][j] =  ans;
        return ans;
    }
    int minDistance(string s1, string s2) {
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        return minops(0,0,s1,s2,s1.length(),s2.length(),dp);
    }
};
