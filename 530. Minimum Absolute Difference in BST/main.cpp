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
class Solution {  //TC:O(N)  SC:O(1)
public:
    int minDiff , prev;
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX , prev = INT_MAX;
         solve(root);
         return minDiff;
    }

    void solve(TreeNode* root) {
        if(root == NULL) return;
        solve(root->left);
        if(prev != INT_MAX){
            minDiff = min(minDiff,abs(root->val - prev));
        }
        prev = root->val;
        solve(root->right);
    }
};
