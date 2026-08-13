class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
           long long  maxi = 0;
    for(int i = 0; i < piles.size(); ++i){
        // sum += piles[i];
        maxi = max((long long)piles[i], maxi);
    }

    long long low = 1, high = maxi;

    while(low<=high) {
        long long mid = low + (high - low) / 2;
        long long hours = 0;

        for(int j = 0; j < piles.size(); ++j) {
            hours += ceil(piles[j] / (mid*1.0)); // Equivalent to ceil(piles[j] / (mid * 1.0))
        }

        if(hours > h) {
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }
    return low;
    }
};
