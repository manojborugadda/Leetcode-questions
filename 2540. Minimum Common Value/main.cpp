class Solution {//TC:O(N+m) SC:O(1)
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        int i = 0 , j = 0;
        while(i < n and j < m) {
            if(nums1[i] < nums2[j]) {
                i++;
            }else if(nums1[i] > nums2[j]) {
                j++;
            }else {
                return nums2[j];
            }
        }
        return -1;
    }
};
