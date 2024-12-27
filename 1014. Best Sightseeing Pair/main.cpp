class Solution {//TC:O(N)  SC:O(1)
public:
    int maxScoreSightseeingPair(vector<int>& values) {
// values[i] + values[j] + i - j can be written as (values[i] + i) + (values[j] - j)
    int maxLeft = values[0];
    int maxScore = INT_MIN;
    for(int i = 1;i<values.size();i++) {
        maxScore = max(maxScore,maxLeft + values[i]-i);
        maxLeft = max(maxLeft,values[i]+i);
    }
    return maxScore;
    }
};
/*
values[i] + values[j] + i - j can be written as (values[i] + i) + (values[j] - j)

Track the maximum value of values[i]+i while iterating through the array.
maxLeft = max(maxLeft,values[i]+i)

and calculate the maximum score of a pair of sightseeing spots by iterating the whole array and update the maxLeft as we should pass the given condition ( i < j )

*/
