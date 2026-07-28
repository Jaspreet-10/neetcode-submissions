class Solution {
public:
    bool bfs(vector<vector<int>>&adj,vector<int>&vis)
    {
        queue<pair<int,int>>q;
        q.push({0,-1});
        while(!q.empty())
        {
            int n=q.front().first;
            int p=q.front().second;
            q.pop();
            vis[n]=1;
            for(auto x:adj[n])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push({x,n});
                }
                else
                {
                    if(x!=p)
                    {
                        return false;
                    }
                }
            }
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        if(bfs(adj,vis)==false)
        {
            return false;
        }
        for(auto x:vis)
        {
            if(x!=1)return false;
        }
        return true; 
    }
};
