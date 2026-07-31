class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, n = numbers.size();
        sort(numbers.begin(), numbers.end());
        for(int i = 0 ; i < n ; ++i){
            int j = 0, k = n-1;
            while(j<k){
                if(numbers[j] + numbers[k] - target == 0) return {j+1, k+1};
                else if(numbers[j] + numbers[k] - target > 0) --k;
                else ++j;
            }
        }
        return {-1, -1};
    }
};
