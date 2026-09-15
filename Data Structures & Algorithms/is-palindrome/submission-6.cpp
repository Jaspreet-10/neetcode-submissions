class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1, n = s.size()-1;
        while(i<=j){
        while(i<=n and !isalnum(s[i]))++i;
        while(j>=0 and !isalnum(s[j])) --j;
        // cout<<s[i]<<" "<<s[j]<<"\n";
        if(tolower(s[i]) != tolower(s[j])) return false;
        ++i, --j;
        }
        return true;
    }
};
