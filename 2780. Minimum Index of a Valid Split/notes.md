https://www.youtube.com/watch?v=znayqMBqaKo



```
/* Approach : Majority Element (Boyer - Moore)
1. Find majority element using Moore Voting Algorithm
2. Try split at each point and check if it is majority in both half
Time : O(n)
Space : O(1)
*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        //find the majority element using Moore's voting algorithm
        int majority = nums[0], count = 1;
        for (int i=1; i<n; i++){
            if(nums[i] == majority)
                count++;
            else
                count--;
            if(count == 0){
                majority = nums[i];
                count = 1;
            }
        }
    
        //get frequency of majority element
        int majorityCount = 0;
        for(auto num: nums)
            if(num == majority)
                majorityCount++;
    
        // traverse array and check if split is possible at this point or not
        int leftCount = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == majority)
                leftCount++;
            // check if it is majority in both half 
            if((leftCount*2 > i+1)  && ((majorityCount - leftCount)*2 > n-i-1)) 
                return i;
        }
        return -1;
    }
};
```
