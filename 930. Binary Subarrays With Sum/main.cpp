class Solution {//TC:O(N) SC:O(N)
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefSumFreqMp;
        int prefSum = 0;
        prefSumFreqMp[0] = 1;
        int subArrayCnt = 0;
        for (int num : nums) {
            prefSum += num;
            if (prefSumFreqMp.find(prefSum - goal) != prefSumFreqMp.end()) {
                subArrayCnt += prefSumFreqMp[prefSum - goal];
            }
            prefSumFreqMp[prefSum]++;
        }   
        return subArrayCnt;
    }
};
