class Solution {//TC/;O(N)  SC:O(N)
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n) , suffix(n);
        vector<int>result(n);

        //calculating prefixsum array and suffixSum array 
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = 1;i<n;i++) {
            prefix[i] = nums[i]+prefix[i-1];
            suffix[n-i-1] = nums[n-i-1]+suffix[n-i];
        } 

        //calculating the Absolute Differences and updating the result vector
        for(int i = 0;i<n;i++) {
            int leftSum =  prefix[i];
            int rightSum = suffix[i];
            int absDiff = ( (nums[i] * i) - leftSum ) + (rightSum - (nums[i] * (n-i-1)));
            result[i] = absDiff;
        }
        return result;
    }
};
