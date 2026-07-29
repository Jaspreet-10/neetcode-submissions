class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            result = result + to_string(strs[i].size()) + "#" + strs[i];
        }
        cout<<result;
        return result;
    }

    vector<string> decode(string s) {
        vector<string>result;
        for(int i = 0 ; i < s.size() ; ++i){
            int count = 0;
        while(s[i]!='#'){
            count = count * 10 + (s[i] - '0');
            ++i;
            }
            result.push_back(s.substr(i+1, count));
            i+=count;
        }
        return result;
    }
};
