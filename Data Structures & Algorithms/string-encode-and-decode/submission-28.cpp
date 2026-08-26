class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            str+=to_string(strs[i].size())+"#"+strs[i];
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        for(int i = 0 ; i < s.size() ; ++i){
            int sum = 0;
            while(s[i]!='#'){
                int ch = s[i] - '0';
                sum = sum*10+ch;
                ++i;
            }
            ans.push_back(s.substr(i+1, sum));
            i+=sum;
        }
        return ans;
    }
};
