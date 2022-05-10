class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        stack<int>s;
        
        vector<int>ans(n);
        
        for(int i = 2*n-1;i>=0;i--)
        {
            
            while(s.empty() == false and s.top() <= nums[i%n]){
                s.pop();
            }
            
            if(s.empty()){
                ans[i%n] = -1;
            }else
            {
                   ans[i%n] = s.top();
            }
            
            s.push(nums[i%n]);
        }
        
        return ans;
    }
};