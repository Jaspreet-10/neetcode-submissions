class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first+second);
            }
            else if(s[i] == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(first!=0)
                st.push(second/first);
            }
            else if(s[i] == "-"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second-first);
            }
            else if(s[i] == "*"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first*second);
            }
            else{
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};
