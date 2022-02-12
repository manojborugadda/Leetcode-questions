class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());
        int l = nums[n-1]*nums[n-2]*nums[n-3];
        int m = nums[0]*nums[1]*nums[n-1];
        return max(l,m);
    }
};