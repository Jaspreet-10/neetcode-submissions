class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>>m;
        vector<vector<string>>ans;
        for(int i = 0 ; i < strs.size() ; ++i){
            vector<int>v(26, 0);
            for(int j = 0 ; j < strs[i].size() ; ++j){
                v[strs[i][j] - 'a']++;
            }
            m[v].push_back(strs[i]);
        }

        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
