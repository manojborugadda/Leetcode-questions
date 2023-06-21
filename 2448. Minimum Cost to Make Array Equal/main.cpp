class Solution {
public:
    long long fnc(long long x ,vector<int> &nums , vector<int> &cost){
        long long t_cost = 0;
        for(int i = 0;i<nums.size();i++)
            t_cost += abs((long long)nums[i] - x)*(long long)cost[i];
        return t_cost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
         int n = nums.size();
         long long low = *min_element(nums.begin() , nums.end());
         long long high = *max_element(nums.begin() , nums.end());
         long long ans = 0;
         while(low<high)
         {
             long long mid = (low+high)/2;
             long long x1 = fnc(mid , nums , cost);
             long long x2 = fnc(mid+1 , nums , cost);
             ans = min(x1 , x2);
             if(x1 > x2)
             {
                 low = mid+1;
             }
             else
             {
                 high = mid;
             }
         }
         return ans;
    }
};
