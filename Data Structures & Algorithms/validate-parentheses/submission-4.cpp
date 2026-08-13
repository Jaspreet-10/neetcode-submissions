class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i = 0;
        while(i<s.size()){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else if(!st.empty() and((s[i] == ']' and st.top() == '[') || (s[i] == '}' and st.top() == '{') || (s[i] == ')' and st.top() == '(')))
            st.pop();
            else return false;
            ++i;
        }
        if(st.empty()) return true;
        return false;
    }
};
