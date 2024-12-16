class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            //finding the min element's INDEX in a vector -- int maxElementIndex = std::max_element(v.begin(),v.end()) - v.begin();
            auto mini_idx = min_element(nums.begin(), nums.end())- nums.begin();
            nums[mini_idx] = nums[mini_idx]*multiplier;
        }
        return nums;
    }
};
