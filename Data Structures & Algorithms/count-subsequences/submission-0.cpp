class Solution {
   public:
    int lcs(int i, int j, int n, int m, string& text1, string& text2, map<pair<int, int>, int>& M) {
        if (j >= m) return 1;
        if (i >= n) return 0;
        pair<int, int> p = {i, j};
        if (M.find(p) != M.end()) return M[p];
        int ans = lcs(i + 1, j, n, m, text1, text2, M);
        if (text1[i] == text2[j]) {
            ans += lcs(i + 1, j + 1, n, m, text1, text2, M);
        }
        M[p] = ans;
        return M[p];
    }
    int numDistinct(string s, string t) {
        map<pair<int, int>, int> m;
        return lcs(0, 0, s.length(), t.length(), s, t, m);
    }
};
