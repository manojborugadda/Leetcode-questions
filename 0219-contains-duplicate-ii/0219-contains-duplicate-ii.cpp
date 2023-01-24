class Solution {  //TC:O(N)  SC:O(N)
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i = 0;i<nums.size();i++) {
            //if we find the duplicate of current number in the MAP we validate "abs(i - j) <= k."
            if(map.find(nums[i]) != map.end() and abs(map[nums[i]] - i) <= k) {
                return true;
            }
            //else
            map[nums[i]] = i;  //insert into the HASHMAP element as KEY and index as VALUE
        }
        return false;
    } 
};
