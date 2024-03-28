class Solution {//TC:O(N) SC:O(1)
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>map;
        int i = 0 , j = 0 , maxlen = 0;
        while(j < n) {
            map[nums[j]]++;
            while(i < j and map[nums[j]] > k) {
                map[nums[i]]--;
                i++;//incrementing the LEFT pointer
            }
            maxlen = max(maxlen , j - i+1);//calculating the len of longest subarray
            j++;//incrementing the RIGHT pointer
        }
        return maxlen;
    }
};
