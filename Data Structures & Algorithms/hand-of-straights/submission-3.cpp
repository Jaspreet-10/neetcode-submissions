class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>m;
        int k = groupSize, n = hand.size();
        if(n%k!=0) return false;
        for(int i = 0 ; i < n ; ++i){
            m[hand[i]]++;
        }
        while(!m.empty()){
            auto it = m.begin();
            int first = it->first;
            while(k>0){
                if(m.find(first)==m.end()) return false;
                m[first]--;
                if(m[first] == 0) m.erase(first);
                first+=1;
                --k;
            }
            k = groupSize;
        }
        return true;
    }
};
