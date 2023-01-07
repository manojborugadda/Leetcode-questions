class Solution {  //TC:O(N)  SC:O(1)
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //base case
        int totalGas=accumulate(gas.begin(),gas.end(),0);
        int totalCost=accumulate(cost.begin(),cost.end(),0);
        if(totalGas<totalCost) return -1;


        int n=gas.size();
        int currGas=0,startIdx=0;
        for(int i=0;i<n;i++)
        {
            currGas+=gas[i]-cost[i];
            if(currGas<0)
            {
                startIdx=i+1;
                currGas=0;
            }
        }
        return startIdx;
    }
};
