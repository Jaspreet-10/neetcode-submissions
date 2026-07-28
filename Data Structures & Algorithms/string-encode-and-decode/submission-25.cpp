class Solution {
public:

    string encode(vector<string>& strs) {
        string initialStr = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            initialStr+= to_string(strs[i].size()) + "#" + strs[i];
        }
        return initialStr;
    }

    vector<string> decode(string s) {
        if(s == "") return {};
        vector<string>result;
        for(int i = 0 ; i < s.size() ; ++i){
            int ans = 0;
            while(s[i]!='#'){
                ans = ans*10+(s[i]-'0');
                ++i;
            }
            result.push_back(s.substr(i+1, ans));
            i+=ans;
        }
        return result;
    }
};
