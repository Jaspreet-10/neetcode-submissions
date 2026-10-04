class Solution {
public:
    bool dfs(int node, vector<bool>&vis, vector<vector<int>>&adjL, int parent){
        vis[node] = true;
        for(auto it:adjL[node]){
            if(vis[it] == false){
                if(dfs(it, vis, adjL, node)) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    bool validTree(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adjL(V);
        vector<bool>vis(V, false);
        for(int i = 0 ; i < n ; ++i){
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }
        if(dfs(0, vis, adjL, -1)) return false;
        for(int i = 0 ; i < V ; ++i){
            if(vis[i]==false) return false;
        }
        return true;
    }
};
