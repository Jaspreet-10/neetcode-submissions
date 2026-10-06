class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>m;
        vector<int>ans;
        int count;
        int maxi = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            m[s[i]] = i;
        }

       for(int i = 0 ; i < s.size() ; ++i){
            maxi = m[s[i]];
            int count = 1;
            while(i<maxi){
                if(m[s[i]]>maxi) maxi = m[s[i]];
                ++count;
                if(i == maxi) break;
                ++i;
            }
            ans.push_back(count);
       }
       return ans;
    }
};
