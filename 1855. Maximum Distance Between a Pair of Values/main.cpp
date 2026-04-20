class Solution { // TC :O(M+N)  SC : O(1)
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i  = 0, j =0 ;
        while(i < nums1.size() and j < nums2.size() ) {
            if(nums1[i] <= nums2[j]) {
                ans = max(ans, j-i);
                j++;
            }else {
                i++;
            }
        }
        return ans;
    }
};
