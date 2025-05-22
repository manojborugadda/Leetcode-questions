class Solution {//TC:O(log Q * (N+Q))  SC:O(N)
public:
    bool cantransform(vector<int>& nums, vector<vector<int>>& queries,int k) {
        int n = nums.size() , sum = 0;
        vector<int>diff(n+1,0);
        for(int i =0;i<k;i++) {
            int l = queries[i][0] , r = queries[i][1] , value = queries[i][2];
            diff[l] += value;
            diff[r+1] -= value;
        }

        //getting the prefix sum of diff
        for(int i=1;i<n;i++)diff[i] += diff[i-1];
        //checking if anyof the diff value is less than nums[i], meaning it cannot be reduced to ZERO
        for(int i = 0;i<n;i++) {
            if(diff[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size(), ans = -1;
        if(!cantransform(nums,queries,right)) {
            return -1;
        }
        while(left <= right) {
            int mid = (left+right)>>1;
            if(cantransform(nums,queries,mid)) {
                right =  mid-1;
                ans = mid;
            }else {
                left = mid+1;
            }
        }
        return ans;
    }
};
