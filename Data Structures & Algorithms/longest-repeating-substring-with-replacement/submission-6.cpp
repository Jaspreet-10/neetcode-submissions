class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>m;
        int i = 0, j = 0, n = s.size(), maxLength = 0, maxi = 0;
        while(i<n){
            m[s[i]]++;
            maxLength = max(maxLength, m[s[i]]);
            while(j<n and i-j-maxLength+1>k){
                m[s[j]]--;
                ++j;
            }
            maxi = max(maxi, i - j + 1);
            ++i;
        }
        return maxi;
    }
};