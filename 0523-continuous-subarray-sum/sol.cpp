class Solution {  //TC:O(N) SC:O(N)
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return false;
        unordered_map<int,int>map;//stores the "Remainder" as KEY and "Ending Index" of the subarray as VALUE
        
//if we encounter first element as multiple of K and it is not having the subarray size morethan 2 the condition for this problem is not meeting the condition and we keep map[0] as -1
        map[0]  = -1;
        int sum = 0,remainder;
        for(int i = 0;i<n;i++) {
            sum = sum+nums[i];
            remainder = sum%k;
            //If the remainder is not present in the MAP before we add it to the Map
            if(map.find(remainder) == map.end()) {
                map[remainder] = i;
            } else if(i-map[remainder] >= 2) { //if the length between the 
                return true;
            }
        }
        return false;
    }
};
