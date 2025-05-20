// 3355. Zero Array Transformation I
class Solution {//TC:O(N+Q)  SC:O(N)
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n+1,0);

        //applying range increments
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
            diff[l]++;
            if(r + 1 < n) {
                diff[r+1]--;
            }
        }

        //building prefix sum array
        vector<int>prefixsum(n,0);
        prefixsum[0] = diff[0];
        for(int i = 1;i<n;i++) {
            prefixsum[i] = prefixsum[i-1]+diff[i];
        }

        //checking if it possible to transform nums into a ZERO Array through applying reverse transformation
        for(int i = 0;i<n;i++) {
            if(nums[i] - prefixsum[i] > 0) {
                return false;
            }
        }
        return true;
    }
};
