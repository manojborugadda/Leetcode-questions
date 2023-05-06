class Solution {//TC:O(nlogn) SC:O(N)
public:
    int numSubseq(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        sort(begin(nums),end(nums));//logn time complexity
        int ans = 0;
        int MOD = 1e9+7;
        vector<int>pow(nums.size(),1);
        int left = 0 , right = nums.size()-1;

        //Taking 2^n prefix in a Vector
        for(int i = 1;i<nums.size();i++) {
            pow[i] = (pow[i-1]*2)%MOD;
        }

        while(left <= right) {
            if(nums[left] + nums[right] > target) {
                right--;
            }else {
                ans = (ans + pow[right-left])%MOD;
                left++;
            }
        }
        return ans;
    }
};
