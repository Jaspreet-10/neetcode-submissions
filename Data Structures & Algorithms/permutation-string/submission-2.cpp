class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n1 = s1.size(), n2 = s2.size();
       vector<int>v1(26, 0), v2(26, 0);
       for(int i = 0 ; i < n1 ; ++i){
            v1[s1[i]-'a']++;
       }
       int i = 0, j = 0;
       while(i<n2 and j<n2){
         v2[s2[i]-'a']++;
         while(i-j+1>n1){
            v2[s2[j]-'a']--;
            ++j;
         }
         if(v1 == v2) return true;
         ++i;
       }
       return false;
    }
};
