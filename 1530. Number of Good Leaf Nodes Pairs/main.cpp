/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> solve(TreeNode* root, int distance, int &ans) {
        if (!root)
            return {};

        // Leaf tells its Parent: I'm 1 distance away from you
        if (!root->left && !root->right)
            return {1};

        vector<int> left = solve(root->left, distance, ans);
        vector<int> right = solve(root->right, distance, ans);

        // Count all good pairs
        for (int i = 0; i < left.size(); i++)
            for (int j = 0; j < right.size(); j++)
                if (left[i] + right[j] <= distance)
                    ans++;

        // Append right to left and then increment all the values by 1
        for (int i = 0; i < left.size(); i++)
            left[i]++;
        for (int i = 0; i < right.size(); i++)
            left.push_back(right[i] + 1);
        return left;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};
