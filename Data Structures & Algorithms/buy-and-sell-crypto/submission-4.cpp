class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxi = 0, n = prices.size();
        for(int i = 1 ; i < n ; ++i){
            if(prices[i]<buy){
                buy = prices[i];
            }
            maxi = max(maxi, prices[i] - buy);
        }
        return maxi;
    }
};
