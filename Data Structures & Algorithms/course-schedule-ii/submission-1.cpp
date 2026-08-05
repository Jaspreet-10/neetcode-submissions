class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>inDegree(n, 0);
        vector<int>adj[n];
        queue<int>q;
        vector<int>v;
        for(int i = 0 ; i < pre.size() ; ++i){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i = 0 ; i < n ; ++i){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        for(int i = 0 ; i < n ; ++i) if(inDegree[i] == 0) q.push(i);
        while(!q.empty()){
            int node = q.front();
            v.push_back(node);
            q.pop();
            for(int i = 0 ; i < adj[node].size() ; ++i){
                inDegree[adj[node][i]]--;
                if(inDegree[adj[node][i]] == 0) q.push(adj[node][i]);
            }
        }
        for(int i = 0 ; i < n ; ++i) if(inDegree[i]!=0) return {};
        return v;
    }
};
