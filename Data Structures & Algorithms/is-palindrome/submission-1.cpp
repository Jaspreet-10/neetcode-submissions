class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i = 0 ; i < s.length() ; ++i){
            if((s[i]-'0'>=0 && s[i]-'0'<=9) ||
            (s[i]-'a'>=0 && s[i]-'z'<=25)) str+=s[i];
        }
        int i = 0, j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            ++i, --j;
        }
        return true;
    }
};
