class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(2 * (1e5 + 1), 0);

        for (int i = 0; i < n; ++i) {
            int startRange = nums[i] - k;
            int endRange = nums[i] + k;

            if (startRange <= 0)
                prefixSum[0] += 1;
            else
                prefixSum[startRange] += 1;

            prefixSum[endRange + 1] -= 1;
        }

        int maxBeauty = 0;
        int size = prefixSum.size();

        for (int i = 1; i < size; ++i) {
            prefixSum[i] += prefixSum[i - 1];
            maxBeauty = max(maxBeauty, prefixSum[i]);
        }

        return maxBeauty;
    }
};
