class Solution {
public:
    static bool comp(string& a, string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        else
            return a < b;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        return nums[nums.size()-k];
    }
};
