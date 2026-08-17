class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        palindromePartioning(0,s,res,path);
        return res;
    }
    void palindromePartioning(int index,string s, 
    vector<vector<string>>&res,vector<string>&path){
        if(index == s.length()){
            res.push_back(path);
            return ;
        }
        for(int i = index ; i < s.length() ; ++i){
            if(isPalidrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                palindromePartioning(i+1,s,res,path);
                path.pop_back();
            }
        }
        return ;
    }
    bool isPalidrome(int start,int end,string s){
        while(start<=end){
            if(s[start]!=s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};
