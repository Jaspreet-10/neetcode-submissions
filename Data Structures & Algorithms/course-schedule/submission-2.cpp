class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<int>v[numCourses];
        vector<int>inDegree(numCourses);
        queue<int>q;
        for(int i = 0 ; i < n ; ++i){
            v[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i = 0 ; i < numCourses ; ++i){
            for(auto it : v[i]){
                inDegree[it]++;
            }
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : v[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i] != 0) return false;
        }
        return true;
    }
};
