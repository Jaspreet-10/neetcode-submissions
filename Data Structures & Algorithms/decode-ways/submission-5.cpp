class Solution {
public:
    int decodeWays(int index, int n, string s, 
    unordered_map<int, int>&dp){
        if(index==n) return 1;
        if(index>n) return 0;
        if(dp.find(index)!=dp.end()) return dp[index];
        int oneWay = 0, secondWay = 0;
        if(s[index]!='0'){
            oneWay = decodeWays(index+1, n, s, dp);
            if(index+2<=n and stoi(s.substr(index, 2))<=26)
                secondWay = decodeWays(index+2, n, s, dp);
        }
        return dp[index] = oneWay + secondWay;
    }
    int numDecodings(string s) {
        int n = s.size();
        unordered_map<int, int>dp;
        return decodeWays(0, n, s, dp);
    }
};
