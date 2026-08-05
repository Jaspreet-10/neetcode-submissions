class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int,int>m;
        for(int i = 0 ; i < n ; ++i){
            m[hand[i]]++;
        }
        while(!m.empty()){
            int k = 0;
            auto it = m.begin();
            int value = it->first;
            while(k<groupSize){
                if(m[value]>0){
                    m[value]--;
                    if(m[value] == 0) m.erase(value);
                }else return false;
                ++value;
                ++k;
            }
        }
        return true;
    }
};
