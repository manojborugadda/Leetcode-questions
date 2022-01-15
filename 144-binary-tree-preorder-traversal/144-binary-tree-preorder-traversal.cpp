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
private:
    void dfs(TreeNode* node,vector<int>&preOrder){
        if(node==NULL) return;
        preOrder.push_back(node->val);
        dfs(node->left,preOrder);
        dfs(node->right,preOrder);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
      vector<int>preOrder;
        dfs(root,preOrder);
        return preOrder;
    }
};