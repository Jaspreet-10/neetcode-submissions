class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0, n = s.size(), maxi = 0;
        unordered_map<char, int>m;
        while(i<n){
            m[s[i]]++;
            while(m[s[i]]>1){
                m[s[j]]--;
                ++j;
            }
            maxi = max(i-j+1, maxi);
            ++i;
        }
        return maxi;
    }
};
