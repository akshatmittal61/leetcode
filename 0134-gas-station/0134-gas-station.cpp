class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totGas = 0, totCost = 0;
        int g = 0, init = 0;
        for(int i = 0; i < n; ++i) {
            totGas += gas[i];
            totCost += cost[i];
        }
        if(totGas < totCost)
            return -1;
        for(int i = 0; i < n; ++i) {
            g = gas[i] - cost[i];
            if( g < 0 ) {
                g = 0, init = i + 1;
            }
        }
        return init;
    }
};