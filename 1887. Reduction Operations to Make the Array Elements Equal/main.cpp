class Solution {//due to sorting TC:O(nlogn) SC:o(1)
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int operations = 0;
        for(int i = n-1;i>=1;i--) {
            if(nums[i] == nums[i-1]) {
                continue;
            }
            operations += (n-i);
        }
        return operations;
    }
};
