class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& p) {
        vector<int>inDegree(num, 0);
        vector<vector<int>>v(num);
        queue<int>q;

        for(int i = 0 ; i < p.size() ; ++i){
            v[p[i][1]].push_back(p[i][0]);
        }
        
        for(int i = 0 ; i < num ; ++i){
            for(auto it : v[i]){
                inDegree[it]++;
            }
        }

        for(int i = 0 ; i < num ; ++i){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto it : v[i]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        for(int i = 0 ; i < num ; ++i)
            if(inDegree[i]!=0) return false;
        return true;
    }
};
