class Solution { 
public:
    
    void helper(vector<int>& nums,vector<vector<int>>&ans,int left,int right){
        if(left == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = left ; i<= right ;i++){
            swap(nums[i],nums[left]);
            helper(nums,ans,left+1,right);
            swap(nums[i],nums[left]); // backtracking
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans; /// answer Vector
        helper(nums,ans,0,nums.size()-1); 
        return ans;
        
    }
    
};