class Solution {
public:
    void recur(int i,vector<int>& nums, vector<int>&temp,vector<vector<int>>&ans){ // we created the function
        if(i == nums.size()){
            ans.push_back(temp);
        }
        else{
            // to take the i'th element
            temp.push_back(nums[i]);
            recur(i+1,nums,temp,ans);
            
            temp.pop_back();  // this is the backtracking part-------------
            // to ignore the i'th element
            recur(i+1,nums,temp,ans);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>temp;
        recur(0,nums,temp,ans) ;
        return ans;
        
    }
};