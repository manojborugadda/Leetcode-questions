class Solution {//TC:O(N)  SC:O(N)
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>map;
        int maxLen = 0 , sum = 0;
        map[0] = -1;//initialising with 0 sum at index -1
        for(int i = 0;i<n;i++) {
            sum += (nums[i] == 1) ? 1 : -1; //increment sum with 1 if we met with 1 and decrement with -1 if we encounter 0 in the nums vector

//if the same sum is encountered in the MAP it means we got contiguous subarray with an equal number of 0 and 1.
            if(map.count(sum)) { 
                maxLen = max(maxLen, i - map[sum]);
            }else {//if we didnot get the sum before we insert into the MAP
                map[sum] = i;
            }
        }
        return maxLen;
    }
};
