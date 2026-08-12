class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>resultOfAnagrams;
        map<vector<int>, vector<string>>m;
        for(int i = 0 ; i < strs.size() ; ++i){
            vector<int>asciiOfChars(26, 0);
            for(int j = 0 ; j < strs[i].size() ; ++j){
                asciiOfChars[strs[i][j] - 'a']++;
            }
            m[asciiOfChars].push_back(strs[i]);
        }
        for(auto it : m){
            resultOfAnagrams.push_back(it.second);
        }
        return resultOfAnagrams;
    }
};
