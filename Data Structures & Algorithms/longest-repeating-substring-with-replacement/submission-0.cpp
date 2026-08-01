class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>m;
        int j = 0, maxCount = 0, ans = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            m[s[i]]++;
            maxCount = max(m[s[i]], maxCount);
            while(m[s[i]]>0 and i-j-maxCount>=k){
                m[s[j]]--;
                maxCount = max(maxCount, m[s[j]]);
                ++j;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
