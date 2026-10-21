class Solution {
public:
    void helper(int n, int open, int close, vector<string>&ans,  
    string str){
        if(open == n and close == n){
            ans.push_back(str);
        }
        if(open>n || close>open) return ;

        if(open<n){
            helper(n, open+1, close, ans, str+'(' );
        }
        if(close<open){
           helper(n, open, close+1, ans, str+')' ); 
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str = "";
        int open = 0, close = 0;
        helper(n, open, close, ans, str);
        return ans;
    }
};
