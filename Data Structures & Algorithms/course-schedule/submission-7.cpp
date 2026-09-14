class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adjL, vector<int>&vis,
    vector<int>&pathVis){
        pathVis[node] = 1;
        vis[node] = 1;
        for(auto it : adjL[node]){
            if(vis[it] == 0){
                if(dfs(it, adjL, vis, pathVis)) return true;
            }else if(pathVis[it] == 1) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>vis(n, 0), pathVis(n, 0);
        vector<vector<int>> adjL(n);
        for(int i = 0 ; i < pre.size() ; ++i){
            adjL[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 0){
                if(dfs(i, adjL, vis, pathVis)) return false;
            } 
        }
        return true;
    }
};
