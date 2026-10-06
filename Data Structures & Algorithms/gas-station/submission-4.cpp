class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, n = gas.size(), index = 0, 
        diff = 0;
        for(int i = 0 ; i < n ; ++i){
            totalGas+=gas[i];
            totalCost+=cost[i];
            diff+= gas[i] - cost[i];
            if(diff<0){
                index = i+1;
                diff = 0;
            }
        }
        return totalGas < totalCost ? -1 : index;
    }
};
