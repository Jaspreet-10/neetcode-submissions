class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>inDegree(n, 0);
        queue<int>q;
        vector<vector<int>> adjL(n);
        for(int i = 0 ; i < pre.size() ; ++i){
            adjL[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i = 0 ; i < n ; ++i){
            for(auto it : adjL[i]){
                inDegree[it]++;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it : adjL[front]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(inDegree[i] != 0) return false;
        }
        return true;
    }
};
