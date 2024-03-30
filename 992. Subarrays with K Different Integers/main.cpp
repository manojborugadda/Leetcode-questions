class Solution {//TC:O(N)  SC:O(N)
public:
    int slidingWindowAtmost(int n,vector<int>&nums) {
        int i = 0 , j = 0 , count = 0;
        unordered_map<int,int>map;
        //map<int,int>map;
        while(j < nums.size()) {
            map[nums[j]]++;
            while(map.size() > n) {//checking for subarray Validity
                map[nums[i]]--;
                if(map[nums[i]] == 0) {//If the frequency becomes 0, remove the element from mp
                    map.erase(nums[i]);
                }
                i++;//Move i forward to shrink the window and maintain the condition.
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //we want no.of good subarrays which  has number of different integers in that array is exactly k.
        //no.of good subarrays= atmost(k) - atmost(k-1)

        return slidingWindowAtmost(k,nums) - slidingWindowAtmost(k-1,nums);
    }
};
