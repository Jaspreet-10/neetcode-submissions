class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string, int>m;
        int size = strs.size(), maxi = 0;
        string ans = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            string str = "";
            for(int j = 0 ; j < strs[i].size() ; ++j){
                str+=strs[i][j];
                m[str]++;
            }
        }
        for(auto it : m){
            if(it.second == size){
                if(it.first.size()>maxi){
                    maxi = it.first.size();
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};