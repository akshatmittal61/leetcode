https://leetcode.com/problems/gas-station

# Approach 1

1. Calculate the total gas and total cost required to complete the circuit.
2. If the amount of total gas is lesser than that of cost, return -1, the trip cannot be completed.
3. Now start from index $0$, check for gas at every station.
4. To get gas at any station, add the max amount of gas that can be taken from this station and remove the amount that will be spent travelling to the next one. -> $currentGas = gas[i] - cost[i]$
5. If the amount of gas left is negative, that means out assumption of starting point was wrong.
6. Reset the current amount to $0$ and and update starting position to the next station.
7. In the end return the starting point.
8. Make sure to handle the case if the first station is starting point.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
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
            g += gas[i] - cost[i];
            if( g < 0 ) {
                g = 0, init = i + 1;
            }
        }
        return init % n;
    }
};
```