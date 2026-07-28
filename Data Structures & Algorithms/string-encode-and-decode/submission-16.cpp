class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string s = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            s = s + to_string(strs[i].size()) + "#" + strs[i];
        }
        cout<<s<<"\n";
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i<s.length()){
            int j = i;
            int sum = 0, len = 0, cnt = 0;
            while(s[j]!='#'){
            sum = sum*10 + (s[j] - 48);
            ++cnt;
            ++j;
            }
            len = sum;
            cout<<len<<" ";
            ans.push_back(s.substr(i+cnt+1,len));
            i = i + cnt + len + 1;
        }
        return ans;
    }
};
