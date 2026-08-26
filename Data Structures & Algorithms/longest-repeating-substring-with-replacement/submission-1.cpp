class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), i = 0, j = 0, maxiCount = 0, maxi = 0;
        unordered_map<char, int>m;
        while(i<n){
            m[s[i]]++;
            maxiCount = max(maxiCount, m[s[i]]);
            while(i-j-maxiCount+1>k){
                m[s[j]]--;
                ++j;
            }
            maxi = max(i-j+1, maxi);
            ++i;
        }
        return maxi;
    }
};
