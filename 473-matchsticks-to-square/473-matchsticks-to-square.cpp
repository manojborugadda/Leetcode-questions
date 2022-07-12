class Solution {
public:
    bool backtrack(vector<int>& matchsticks,vector<int>& v, int target, int curr_sum, int i, int k) {
        if (k == 1) {
            return true;
        }
        if (curr_sum == target) {
            return backtrack(matchsticks, v, target, 0, 0, k - 1);
        }
        for (int j = i; j < matchsticks.size(); j++) {
            if (v[j] || curr_sum + matchsticks[j] > target) {
                continue;
            }
            v[j] = true;
            if (backtrack(matchsticks, v, target, curr_sum + matchsticks[j], j + 1, k)) return true;
            v[j] = false;
        }
        return false;
    }
    int sum_vector(vector<int>& matchsticks) {
        int ans = 0;
        for(int i = 0; i < matchsticks.size(); i++) {
            ans += matchsticks[i];
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = sum_vector(matchsticks);
        if(matchsticks.size() < 4 || sum % 4 != 0) {
            return false;
        }
        vector<int> v(matchsticks.size(), false);
        return backtrack(matchsticks, v, sum / 4, 0, 0, 4);
    }
};