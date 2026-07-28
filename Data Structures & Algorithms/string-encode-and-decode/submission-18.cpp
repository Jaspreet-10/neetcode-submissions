class Solution {
public:

    string encode(vector<string>& strs) {
        string e = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            e = e + to_string(strs[i].length()) + "#" + strs[i];
        }
        cout<<e<<" ";
        return e;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        for(int i = 0 ; i < s.length() ; ++i){
            int digit = 0;
            while(s[i]!='#' and i<s.length()){
                digit = digit*10 + (s[i] - '0');
                ++i;
            }
            // cout<<s.substr(i+1,digit)<<" ";
            ans.push_back(s.substr(i+1,digit));
            i+=digit;
        }
        return ans;
    }
};
