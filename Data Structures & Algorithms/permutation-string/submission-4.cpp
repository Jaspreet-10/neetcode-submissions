class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0, j = 0, n1 = s1.size(), n2 = s2.size();
        vector<int>t1(26, 0), t2(26, 0);
        for(int i = 0 ; i < n1 ; ++i){
            t1[s1[i]-'a']++;
        }
        while(i<n2){
            t2[s2[i]-'a']++;
            while(j<n2 and i-j+1>n1){
                t2[s2[j]-'a']--;
                ++j;
            }
            if(t1 == t2) return true;
            ++i;
        }
        return false;
    }
};
