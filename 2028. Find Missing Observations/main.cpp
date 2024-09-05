class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int total = 0, m = rolls.size();
    for (int it: rolls)
        total += it;
    int missing_sum = mean * (m + n) - total;
    if (missing_sum < n || missing_sum > 6 * n)
        return {};  // The first two if's are handled
    // Each will get distribution
    int distribution = missing_sum / n, remaining = missing_sum % n;
    vector<int> ans(n, distribution);
    // We distribute the remaining to each
    for (int i = 0; i < remaining; i++)
        ++ans[i];
    return ans;
  }
};
