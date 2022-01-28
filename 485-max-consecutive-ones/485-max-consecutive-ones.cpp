class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c++;
                ans = max(ans,c);
            }else{
                
                c  = 0;
            }
        }
        
        return ans;
    }
};