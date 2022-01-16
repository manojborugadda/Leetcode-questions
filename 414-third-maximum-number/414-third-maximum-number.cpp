class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,bool>mp;
        for(auto i : nums) mp[i] = true;
        nums = {};
        for(auto i : mp) nums.push_back(i.first);
        int n = nums.size();
        return (n < 3) ? nums[n-1] : nums[n-3];
    }
};