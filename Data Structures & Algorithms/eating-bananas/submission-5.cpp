class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i = 0 ; i < piles.size() ; ++i){
            maxi = max(maxi, piles[i]);
        }

        int low = 1, high = maxi;
        while(low<=high){
            long long mid = low+(high-low)/2;
            double hours = 0;
            for(int i = 0 ; i < piles.size() ; ++i){
                hours+=ceil((double)(piles[i]/(mid*1.0)));
            }
            if(hours<=h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
