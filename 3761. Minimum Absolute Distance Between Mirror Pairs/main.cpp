class Solution {
public:
    int reverseNum(int n) {//TC:O(logn)  SC : O(1)
        int rev = 0;
        while(n) {
            rev = rev * 10 + n % 10;
            n /=10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>map;
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i++) {
            if(map.count(nums[i])) {
                ans = min(ans,abs(i - map[nums[i]]));
            }
            int reverse  = reverseNum(nums[i]);
            map[reverse] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
