class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalGas = 0, totalCost = 0, index = 0, cur_gas = 0;
        for(int i = 0 ; i < n ; ++i){
            totalGas+=gas[i];
            totalCost+=cost[i];
            cur_gas+=gas[i] - cost[i];
            if(cur_gas<0){
                cur_gas = 0;
                index = i+1;
            }
        }
        return totalCost>totalGas ? -1 : index;
    }
};
