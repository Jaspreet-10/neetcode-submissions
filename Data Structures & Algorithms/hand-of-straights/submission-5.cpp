class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        int groups = n/groupSize;
        map<int, int>m;

        for(int i = 0 ; i < n ; ++i){
            m[hand[i]]++;
        }

        while(m.size()>0){
            auto it = m.begin();
            int first = it->first;
            int k = 0;
            while(k<groupSize and groups>0){
                if(m[first]>0){
                    m[first]--;
                    if(m[first] == 0) m.erase(first);
                }
                else return false;
                first+=1;
                ++k;
            }
            --groups;
        }
        return true;
    }
};
