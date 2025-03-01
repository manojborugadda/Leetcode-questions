class Solution {//TC:O(n)  SC:O(n)
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n-1;i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int>ans;
        for(int num : nums) {
            if(num != 0) {
                ans.push_back(num);
            }
        }

        int count = n - ans.size();//getting the zero elements counts which needs to added at back of vector
        while( count) {
            ans.push_back(0);
            count--;
        }
        return ans;
    }
};
