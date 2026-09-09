class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), maxi = 0;
        for(int i = 0 ; i < n ; ++i){
            maxi = max(piles[i], maxi);
        }
        int low = 1, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            double hours = 0;
            for(int i = 0 ; i < n ; ++i){
                hours+=ceil(double(piles[i]/(mid*1.0)));
            }
            if(hours<=h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
