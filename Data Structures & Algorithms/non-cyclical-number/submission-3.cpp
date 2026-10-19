class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int>m;
        bool flag = true;
        while(flag){
            int sum = 0;
            while(n>0){
                int r = n%10;
                sum = sum+r*r;
                n/=10;
            }
            if(m[sum]>0) return false;
            m[sum]++;
            if(sum == 1) return true;
            n = sum;
        }
        return false;
    }
};
