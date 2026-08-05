class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         vector<vector<int>>adjL(n);
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        for(int i = 0 ; i < edges.size() ; ++i){
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }
        q.push({0, -1});
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adjL[node]){
                if(vis[it] == 0){
                    q.push({it, node});
                     vis[it] = 1;
                }
                else if(vis[it]!=0 and it!=parent) return false;
            }
        }
        for(auto it:vis){
            if(it == 0) return false;
        }
        return true;
    }
};
