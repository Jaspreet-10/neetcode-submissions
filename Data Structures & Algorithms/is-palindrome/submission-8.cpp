class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            while(i<j and !isalnum(s[i])) ++i;
            while(i<j and !isalnum(s[j])) --j;
            if(i<j and std::tolower(s[i]) != std::tolower(s[j])) return false;
            ++i;
            --j;
        }
        return true;
    }
};
