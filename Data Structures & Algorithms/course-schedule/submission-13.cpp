class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adjL, vector<int>&vis, 
    vector<int>&pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adjL[node]){
            if(vis[it] == 0){
                if(!dfs(it, adjL, vis, pathVis)) return false;
            }else if(pathVis[it] == 1) return false;
        }
        pathVis[node] = 0;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>inDegree(n, 0);
        vector<vector<int>> adjL(n);
        vector<int>vis(n, 0), pathVis(n, 0);

        for(int i = 0 ; i < pre.size() ; ++i){
            adjL[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i = 0 ; i < adjL.size() ; ++i){
            for(auto it : adjL[i]){
                inDegree[it]++;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 0){
                if(!dfs(i, adjL, vis, pathVis)) return false;
            }
        }

        for(int i = 0 ; i < n ; ++i){
            if(vis[i]!=1) return false;
        }
        return true;
    }
};
