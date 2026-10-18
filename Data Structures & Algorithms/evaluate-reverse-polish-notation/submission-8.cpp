class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        for(int i = 0 ; i < s.size() ; ++i){
           if (s[i] != "+" && s[i] != "-" &&
                s[i] != "*" && s[i] != "/") {
                st.push(stoi(s[i]));
            }       
            else{
                if(s[i] == "+"){
                    int t1 = st.top(); st.pop();
                    int t2 = st.top(); st.pop();
                    st.push(t1 + t2);
                }

                else if(s[i] == "-"){
                    int t1 = st.top(); st.pop();
                    int t2 = st.top(); st.pop();
                    st.push(t2 - t1);
                }

                else if(s[i] == "/"){
                    int t1 = st.top(); st.pop();
                    int t2 = st.top(); st.pop();
                    if(t1!=0)
                    st.push(t2 / t1);
                    else st.push(0);
                }

                else if(s[i] == "*"){
                    int t1 = st.top(); st.pop();
                    int t2 = st.top(); st.pop();
                    st.push(t1 * t2);
                }
            }
        }
        return st.top();
    }
};
