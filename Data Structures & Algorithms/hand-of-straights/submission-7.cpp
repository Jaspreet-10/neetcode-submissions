class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>m;
        if(hand.size()%groupSize!=0) return false;
        for(int i = 0 ; i < hand.size() ; ++i){
            m[hand[i]]++;
        }

        while(m.size()>0){
            auto it = m.begin();
            int val = it->first;
            int k = 0;
            while(k<groupSize){
                if(m[val]>0){
                m[val]--;
                if(m[val] == 0) m.erase(val);
                ++val;
                }else return false;
                ++k;
            }
        }
        return true;
    }
};
