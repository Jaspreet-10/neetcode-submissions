class Solution {
public:
    int dfs(int node, vector<vector<int>>&adjL, vector<int>&vis){
        vis[node] = 1;
        for(auto it:adjL[node]){
            if(vis[it] == 0){
                dfs(it, adjL, vis);
            }
        }
        return 0;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjL(n);
        vector<int>vis(n,0);
        int count = 0;
        for(int i = 0 ; i < edges.size() ; ++i){
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 0){
                ++count;
                dfs(i, adjL, vis);
            }
        }
        return count;
    }
};
