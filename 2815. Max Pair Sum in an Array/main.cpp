class Solution {
public:
    int getMaxNum(int num) {//func for getting the LARGEST digit in the number
        int maxElem = 0;
        while(num) {
            int rem = num%10;
            maxElem = max(rem , maxElem);
            num = num/10;
        }
        return maxElem;
    }
    int maxSum(vector<int>& nums) {//TC:O(N^2)  SC:O(1)
        int maxSum = INT_MIN;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j = i+1;j<nums.size();j++) {
                if(getMaxNum(nums[i]) == getMaxNum(nums[j])) {
                    int sum = nums[i]+nums[j];
                    maxSum = max(maxSum , sum);
                }
            }
        }
        return maxSum == INT_MIN ? -1 : maxSum;
    }
};
