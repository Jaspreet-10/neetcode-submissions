class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>remaining(128,0);
        int i = 0, left = 0, required = t.size(), mini = INT_MAX, start = 0;
        for(int i = 0 ; i < t.size() ; ++i){
            remaining[t[i]]++;
        }
       while(i<=s.size() && left<s.size()){
            if(required){
                if(remaining[s[i]]>0) --required;
                remaining[s[i]]--;
                ++i;
            }else{
                if(i-left<mini){
                    start = left;
                    mini = i-left;
                }
                remaining[s[left]]++;
                if(remaining[s[left]]>0) ++required;
                ++left;
            }
        }
        return (mini == INT_MAX ? "" : s.substr(start,mini));
    }
};
