class Solution {//TC:O(N) SC:O(1)
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 , countOfZeros = 0;
        for(auto num : nums) {
            if(num == 0) {
                countOfZeros += 1;
            }else {
                countOfZeros = 0;
            }
            ans  += countOfZeros;
        } 
    return ans;
    }
};

// [0,0,0,2,0,0]
//  1 2 3 0 1 2-------count of the ZEROES consecutively
//  1 3 6 6 7 9

