class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0 ; i < tokens.size() ; ++i){
            int first, second;
            if(tokens[i] == "+"){
               if(!st.empty()){
                first = st.top();
                st.pop();
               }
               if(!st.empty()){
                second = st.top();
                st.pop();
               }
               st.push(first+second);
            }
            else if(tokens[i] == "*"){
                if(!st.empty()){
                first = st.top();
                st.pop();
               }
               if(!st.empty()){
                second = st.top();
                st.pop();
               }
               st.push(first*second);
            }
            else if(tokens[i] == "/"){
                if(!st.empty()){
                first = st.top();
                st.pop();
               }
               if(!st.empty()){
                second = st.top();
                st.pop();
               }
               if(first!=0)
               st.push(second/first);
            }
            else if(tokens[i] == "-"){
                if(!st.empty()){
                first = st.top();
                st.pop();
               }
               if(!st.empty()){
                second = st.top();
                st.pop();
               }
               st.push(second-first);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
