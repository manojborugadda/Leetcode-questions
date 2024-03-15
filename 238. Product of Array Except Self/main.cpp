class Solution {//TC:O(N) SC:O(1)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int>ans(n,0);
        int prePro = 1 , suffPro = 1;
        //leftside product
        for(int i = 0;i<n;i++) {
            ans[i] = prePro;
            prePro *= nums[i];
        }
        for(int i = n-1;i>=0;i--) {
            ans[i] *= suffPro;
            suffPro *= nums[i];
        }
        return ans;
    }
};
