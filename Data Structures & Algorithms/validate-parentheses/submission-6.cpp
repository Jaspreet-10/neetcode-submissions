class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                cout<<s[i]<<" ";
                if(s[i] == ')' and !st.empty() and st.top() == '(') st.pop();
                else if(s[i] == '}' and !st.empty() and st.top() == '{') st.pop();
                else if(s[i] == ']' and !st.empty() and st.top() == '[') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
