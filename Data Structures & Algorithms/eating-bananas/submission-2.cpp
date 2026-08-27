class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0, n = piles.size();
        for(int i = 0 ; i < n ; ++i){
            maxi = max(maxi, piles[i]);
        }
        int low = 1, high = maxi;
        while(low<=high){
            long long time = 0;
            int mid = low + (high - low) / 2;
            for(int i = 0 ; i < n ; ++i){
                time+=ceil(piles[i]/(mid*1.0));
            }
            if(time>h) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
