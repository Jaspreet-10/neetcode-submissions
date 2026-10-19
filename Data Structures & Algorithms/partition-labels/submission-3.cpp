class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<int,int>m;
        int maxi = 0, count = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            m[s[i]] = i;
        }

        for(int i = 0 ; i < s.size() ; ++i){
             ++count;
             if(m.find(s[i])!=m.end()){
                if(m[s[i]] > maxi) maxi = m[s[i]];
             }
             if(maxi == i){
                ans.push_back(count);
                maxi = 0;
                count = 0;
             }
        }
        return ans;
    }
};
