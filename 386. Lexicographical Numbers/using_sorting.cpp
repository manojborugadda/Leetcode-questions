class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> nums;
        vector<int> ans;

        // Convert numbers to strings
        for (int i = 1; i <= n; ++i) {
            nums.push_back(to_string(i));
        }

        // Sort strings lexicographically
        sort(nums.begin(), nums.end());

        // Convert sorted strings back to integers
        for (const string& num : nums) {
            ans.push_back(stoi(num));
        }

        return ans;
    }
};
