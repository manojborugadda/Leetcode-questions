class Solution {//TC:O(N)  SC:O(N)
public:
    int helper(vector<int>odds,int goal) {
       if (goal < 0) {
            return 0;
        }
        int count = 0, sum = 0;
        int start = 0, end = 0;
        while (start < odds.size()) {
            sum += odds[start]; 
            while (end < odds.size() and sum > goal) {
                sum -= odds[end];
                end++;
            }
            count += start - end + 1;
            start++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //No. of subarrays with exactly k odd = No. of subarrays with at most k odd - No. of subarrays with at most k-1 odd.
        vector<int>odds;
        for(auto x : nums) {
            if(x %2 == 0) {
                odds.push_back(0);
            }else {
                odds.push_back(1);
            }
        }
        return helper(odds,k) - helper(odds,k-1);
    }
};
