class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, n = s.size(), maxi = 0, ans = 0;
        unordered_map<char, int>m;
        while(i<n){
            m[s[i]]++;
            maxi = max(m[s[i]], maxi);
            while(i-j-maxi+1>k){
                m[s[j]]--;
                ++j;
            }
            ans = max(ans, i-j+1);
            ++i;
        }
        return ans;
    }
};
