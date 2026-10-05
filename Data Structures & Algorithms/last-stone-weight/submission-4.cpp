class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i = 0 ; i < stones.size() ; ++i) pq.push(stones[i]);
        while(pq.size()>1){
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            if(t1 != t2) pq.push(abs(t1-t2));
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};
