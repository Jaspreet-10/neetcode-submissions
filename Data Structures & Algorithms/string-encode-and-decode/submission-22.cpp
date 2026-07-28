class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            str+= to_string(strs[i].size())+ "#" +strs[i];
        }
        cout<<str<<" ";
        return str;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        for(int i = 0 ; i < s.size() ; ++i){
            int dig = 0;
            while(s[i]!='#'){
                dig = dig*10+s[i]-'0';
                ++i;
            }
            ans.push_back(s.substr(i+1, dig));
            i+=dig;
        }
        return ans;
    }
};
