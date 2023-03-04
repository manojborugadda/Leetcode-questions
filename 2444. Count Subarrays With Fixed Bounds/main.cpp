class Solution { //TC:O(N)  SC:O(1)
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minI=-1;
        int maxI=-1;
        long ans =0;
        int start=0;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] < minK or nums[i] > maxK) {//Boundary condition for a window
                minI=maxI=-1;
                start=i+1;
            }

            if(nums[i]==minK) {//if the MIN element is encountered we update the index of that
                minI=i;
            }

            if(nums[i]==maxK) {//if the max element is encountered we update the maxI
                maxI=i;
            }

            ans=ans+max(0,min(minI,maxI)-start+1);
        }
        return ans;
    }
};
