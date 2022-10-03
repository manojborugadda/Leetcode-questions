class Solution {  //TC:O(N)  SC:O(1)
public:// TWO POINTER approach 
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int start = 0 , end = 0;
        int totalTime = 0;
        while(start < n and end < n) {
            int maxTime = 0;
            int groupTotal = 0; //sum of like colour baloon's neededTIME
            //if we got the same colour baloons consectively we just take the MAX element and sum of the same baloon needed TIME
            while(end < n and colors[start] == colors[end]) {
                maxTime = max(maxTime,neededTime[end]);
                groupTotal += neededTime[end];
                end++;
            }
            totalTime += (groupTotal - maxTime);
            start = end;
        }
        return totalTime;
    }
};