class Solution {//TC:O(N)  SC:O(1)
public:
    bool isParity(int a,int b) {
        if ( (a % 2 == 0 and b % 2 == 0) or ( a % 2 != 0 and b % 2 != 0 ) ) {
            return false;
        }
        return true;
    }
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return true;
        int i = 0;
        int j = 0;
        while( i < n-1) {
            j = i+1;
            if(!isParity(nums[i],nums[j])) {
                return false;
            }
            i++;
        }
        return true;
    }
};
