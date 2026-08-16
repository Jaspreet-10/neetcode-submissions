class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char, int>m;
        for(int i = 0 ; i < s.size() ; ++i) m[s[i]] = i;
        int reached = m[s[0]], count = 0;
        for(int i = 0 ; i < s.size() ; ++i){   
            // cout<<s[i]<<" "<<reached<<"\n";
            if(m[s[i]]>reached) reached = m[s[i]];
            ++count;
            if(i == reached){
                ans.push_back(count);
                if(i+1<m.size())
                reached = m[s[i+1]];
                count = 0;
            }   
        }
        return ans;
    }
};
