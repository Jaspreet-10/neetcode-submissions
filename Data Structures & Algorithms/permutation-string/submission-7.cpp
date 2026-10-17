class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26, 0), v2(26, 0);
        int i = 0, j = 0, n1 = s1.size(), n2 = s2.size();
        
        for(int i = 0 ; i < n1 ; ++i){
            v1[s1[i] - 'a']++;
        }

        while(i<n2){
            v2[s2[i] - 'a']++;
            while(j<n2 and i-j+1>=n1){
                if(v1 == v2) return true;
                v2[s2[j] - 'a']--;
                ++j;
            }
            ++i;
        }
        return false;
    }
};
