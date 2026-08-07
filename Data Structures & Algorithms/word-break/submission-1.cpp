class Solution {
public:
    bool checkWordBreak(int index, int n, string s, set<string>&st, vector<int>&dp){
        if(index>=n) return true;
        if(dp[index]!=-1) return dp[index];
        string str = "";
        for(int i = index; i<n ; ++i){
            str+=s[i];
            if(st.find(str)!=st.end()){
            if(checkWordBreak(i+1, n, s, st, dp)) return true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(n, -1);
        return checkWordBreak(0, n, s, st, dp);
    }
};
