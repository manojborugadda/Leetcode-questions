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
public:
    vector<TreeNode*>helper(int start , int end) {
        if(start > end) {
            vector<TreeNode*>nothing = {nullptr};
            return nothing;
        }
        vector<TreeNode*>ans;
        for(int i = start ; i<= end;i++) {
            vector<TreeNode*>leftPossibleTrees = helper(start , i-1);
            vector<TreeNode*>rightPossibleTrees = helper(i+1 , end);
            for(TreeNode* leftTree :leftPossibleTrees ) {
                for(TreeNode* rightTree :rightPossibleTrees ) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right  = rightTree;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    } 
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1,n);
    }
};
