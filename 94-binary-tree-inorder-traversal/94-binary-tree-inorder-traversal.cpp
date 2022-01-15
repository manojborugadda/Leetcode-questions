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
    void dfs(TreeNode* node,vector<int>&Inorder){
        if(node==NULL) return;
        dfs(node->left,Inorder);
        Inorder.push_back(node->val);
        dfs(node->right,Inorder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>Inorder;
        dfs(root,Inorder);
        return Inorder;
    }
};