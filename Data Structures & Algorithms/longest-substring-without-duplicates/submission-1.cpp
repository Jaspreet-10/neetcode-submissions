class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int j = 0, maxi = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            while(m[s[i]]>0){
                m[s[j]]--;
                ++j;
            }
        maxi = max(maxi, i-j+1);
        m[s[i]]++;
        }
        return maxi;
    }
};
