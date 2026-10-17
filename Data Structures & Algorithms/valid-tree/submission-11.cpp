class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adjL, vector<int>&vis, int parent){
        vis[node] = 1;
        for(auto it : adjL[node]){
            if(vis[it] == 0){
                if(dfs(it, adjL, vis, node)) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int parent = -1;
        vector<vector<int>>adjL(n);
        vector<int>vis(n, 0);
        for(int i = 0 ; i < edges.size() ; ++i){
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }

        
        if(dfs(0, adjL, vis, parent)) return false;

        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};
