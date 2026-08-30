class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<int>inDegree(numCourses, 0);
        vector<vector<int>> adjL(numCourses);
        queue<int>q;
        for(int i = 0 ; i < pre.size() ; ++i){
            adjL[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i = 0 ; i < adjL.size() ; ++i){
            for(auto it : adjL[i]){
                inDegree[it]++;
            }
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i] == 0){
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto it : adjL[ele]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i]!=0) return {};
        }
        return ans;
    }
};
