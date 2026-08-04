class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>m{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},
        {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string>temp;
        int ch = digits[0]-'0';
        string s = m[ch];
        for(int i = 0 ; i < s.size() ; ++i){
            string str = "";
            str+=s[i];
            temp.push_back(str);
        }
        for(int i = 1 ; i < digits.size() ; ++i){
            ch = digits[i]-'0';
            s = m[ch];
            vector<string>t1;
            for(int j = 0 ; j < temp.size() ; ++j){
                // cout<<temp[j]<<" ";
                for(int k = 0 ; k < s.size() ; ++k){
                    string str = (temp[j]+s[k]);
                    t1.push_back(str);
                }
            }
            temp = t1;
        }
        return temp;
    }
};
