class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        unordered_map<int,int> hm;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result += hm[nums[i]];
            hm[nums[i]]++;
        }
        return result;
    }
};