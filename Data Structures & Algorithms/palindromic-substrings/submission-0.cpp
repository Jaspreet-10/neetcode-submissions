class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<bool>>v(n, vector<bool>(n, false));
        for(int i = 0 ; i < n ; ++i){
            v[i][i] = true;
            ++count;
        }
        for(int i = 0 ; i < n-1 ; ++i){
            if(s[i] == s[i+1]){
            v[i][i+1] = true;
            ++count;
            }
        }
        for(int j = 2 ; j < n ; ++j){
            for(int k = 0 ; k <=n-j ; ++k){
                if(s[k] == s[k+j] && v[k+1][k+j-1]){
                    v[k][k+j] = true;
                    ++count;
                }
            }
        }
        return count;
    }
};
