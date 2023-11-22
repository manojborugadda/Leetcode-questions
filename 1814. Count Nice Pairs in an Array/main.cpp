class Solution {//TC:O(N)  SC:o(N)
public:
    int reverseOfNum(int num) {
        int ans = 0;
        while(num != 0) {
            int rem = num%10;
            ans = ans*10 + rem;
            num = num/10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9+7;
        int ans = 0;
        unordered_map<int,int>map;
        for(auto num : nums) {
            int diff = num - reverseOfNum(num);
            ans = (ans + map[diff])%MOD;
            map[diff]++;
        }

        return ans%MOD;
    }
};
