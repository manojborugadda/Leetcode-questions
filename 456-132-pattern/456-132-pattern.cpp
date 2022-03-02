class Solution {
public:
    bool find132pattern(vector<int>& nums){
        if(nums.size() <= 2) return false;
         int s2 = INT_MIN; // intially we take second number as INT_MIN 
        stack<int> stk; 
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] < s2) return true; 
            while(stk.empty()== false and stk.top() < nums[i]){
                s2 = max(s2, stk.top()); 
                stk.pop(); 
            }
            stk.push(nums[i]); 
        }
        return false; 
    }
};