class Solution {
public:
    int helper(int index, int n, string s, set<string>&st, 
    vector<int>&dp){
        if(index>=n) return 1;
        if(dp[index]!=-1) return dp[index];
        string str = "";
        for(int i = index ; i < s.size() ; ++i){
            str+=s[i];
            if(st.find(str)!=st.end())
                if(helper(i+1, n, s, st, dp)) return 1;
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int>dp(n, -1);
        return helper(0, n, s, st, dp);
    }
};
