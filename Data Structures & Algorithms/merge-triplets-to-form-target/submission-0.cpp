class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false, second = false, third = false;
        for(auto it:triplets){
            if(it[0]>target[0] || it[1]>target[1] || it[2]>target[2]) continue;
            if(it[0] == target[0]) first = true;
            if(it[1] == target[1]) second = true;
            if(it[2] == target[2]) third = true;
        }
        return first&&second&&third;
    }
};
