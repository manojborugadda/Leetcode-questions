class Solution {//TC:O(N)  SC:O(N)
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>map;
        int maxFreq = INT_MIN;
        for(auto num : nums) {
            map[num]++;
            maxFreq = max(maxFreq,map[num]);
        }

        int mxFreqCnt = 0;
        for(auto [a,b]:map) {
            if(b == maxFreq) {
                mxFreqCnt++;
            }
        }
        return maxFreq * mxFreqCnt;
    }
};

/*
[1,2,2,3,1,4]

Key--freq
1 -- 1
2 -- 2
3 -- 1
1 -- 2
4 -- 1

highest count is 2 and it is appearing 2 different elements
 == 2 * 2 = 4

**/
