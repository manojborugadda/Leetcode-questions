class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&ans, set<vector<int>>&s,int left,int right){
        // if the current permutation IS NOT there in the Set before the we will INSERT 
        if(left==nums.size() and  s.find(nums) == s.end() ){
            ans.push_back(nums);
            s.insert(nums);
            return;
        }
        
         for(int i = left ; i<=right ;i++){
            swap(nums[i],nums[left]);
            helper(nums,ans,s,left+1,right);
            swap(nums[i],nums[left]); // backtracking
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        helper(nums,ans,s,0,nums.size()-1);
        return ans;
    }
};