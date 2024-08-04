class Solution {//TC:O(N^2+nlong) SC:O(N)
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sumArr;
        for(int i = 0;i<n;i++) {
            int temp = 0;
            for(int j = i;j<n;j++) {
                temp += nums[j];
                sumArr.push_back(temp);
            }
        }

        int MOD = 1e9+7;
        sort(begin(sumArr),end(sumArr));
        int ans = 0;
        for(int i = left-1;i<right;i++) {
            ans = (ans + sumArr[i] )%MOD;
        }
        return ans;
    }
};
