class Solution {
public:
    bool dfs(int i, vector<vector<int>>&adjL, vector<int>&vis,
    vector<int>&pathVis){
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto it : adjL[i]){
            if(vis[it] == 0){
                if(dfs(it, adjL, vis, pathVis)) return true;
            }else if(pathVis[it]!=0) return true;
        }
        pathVis[i] = 0;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& p) {
        vector<vector<int>>adjL(num);
        vector<int>vis(num, 0);
        vector<int>pathVis(num, 0);

        for(int i = 0 ; i < p.size() ; ++i){
            adjL[p[i][1]].push_back(p[i][0]);
        }
        
        for(int i = 0 ; i < num ; ++i){
            if(vis[i] == 0){
                if(dfs(i, adjL, vis, pathVis)) return false;
            }
        }
        return true;
    }
};
