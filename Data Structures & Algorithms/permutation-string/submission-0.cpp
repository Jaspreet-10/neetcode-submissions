class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26, 0), v2(26, 0);
        int j = 0;
        for(int i = 0 ; i < s1.size() ; ++i) v1[s1[i]-'a']++;
        for(int i = 0 ; i < s2.size() ; ++i){
            v2[s2[i]-'a']++;
            if(v1 == v2) return true;
            if(i-j+1>=s1.size()){
                v2[s2[j]-'a']--;
                ++j;
            }
        }
        return false;
    }
};
