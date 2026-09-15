class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), maxi = 0;
        unordered_map<char, int>m;
        while(i<n){
            m[s[i]]++;
            while(j < n and m[s[i]]>1){
                m[s[j]]--;
                ++j;
            }
            maxi = max(maxi, i - j + 1);
            ++i;
        }
        return maxi;
    }
};
