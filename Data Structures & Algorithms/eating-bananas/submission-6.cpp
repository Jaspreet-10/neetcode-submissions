class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 1;
        for(int i = 0 ; i < piles.size() ; ++i){
            maxi = max(maxi, piles[i]);
        }

        long long low = 0, high = maxi;
        while(low<=high){
            long long mid = (high-low)/2 + low;
            double hours = 0.0;
            for(int i = 0 ; i < piles.size() ; ++i){
                hours+=ceil(piles[i]/(mid*1.0));
            }
            cout<<hours<<" ";
           if(hours>h) low = mid+1;
           else high = mid-1;
        }

        return low;
    }
};
