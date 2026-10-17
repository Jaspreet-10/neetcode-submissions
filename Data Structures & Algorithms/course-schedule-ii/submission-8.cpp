class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjL(numCourses);
        vector<int>inDegree(numCourses, 0);
        queue<int>q;
        vector<int>ans;
        
        for(int i = 0 ; i < prerequisites.size() ; ++i){
            adjL[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0 ; i < numCourses ; ++i){
            for(auto it : adjL[i]){
                inDegree[it]++;
            }
        }

        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it : adjL[front]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i]!=0) return {};
        }
        
        return ans;
    }
};
