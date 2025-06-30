class Solution {//TC:O(N)  SC:O(N)
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>map;
        for(int i = 0;i<n;i++) {
            map[nums[i]]++;
        }
        int ans = 0;
        for(auto [a,b] : map) {// a-- key, b--- frequency
            if(map.count(a+1)) {
                ans = max(ans,b + map[a+1]);
            }
        }
        return ans;
    }
};

/****

To find the longest harmonious subsequence:

Count the frequency of each element using a hash map.
For every element x, check if x + 1 exists in the map.
If it does, the potential length of the harmonious subsequence is hash[x] + hash[x+1].
Track the maximum of such valid pairs.

****/
