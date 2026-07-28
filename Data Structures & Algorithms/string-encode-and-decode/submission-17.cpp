class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            s = s + to_string(strs[i].length()) + "#" + strs[i];
        }
        cout<<s<<"\n";
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i<s.length()){
            int len = 0;
            while(s[i]!='#'){
                len = len * 10 + s[i] - '0';
                ++i;
            }
            ans.push_back(s.substr(i+1, len));
            i = i + len + 1;
        }
        return ans;
    }
};
