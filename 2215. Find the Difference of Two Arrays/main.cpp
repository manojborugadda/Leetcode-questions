class Solution {//TC:O(N) SC:O(N)
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2,vector<int>(0));
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(begin(nums2),end(nums2));

        for(int num:s1) {
            if(!s2.count(num)) {
                ans[0].push_back(num);
            }
        }

        for(int num:s2) {
            if(!s1.count(num)) {
                ans[1].push_back(num);
            }
        }
        return ans;
    }
};
