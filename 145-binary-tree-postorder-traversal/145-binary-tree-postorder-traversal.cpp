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
    void dfs(TreeNode* node,vector<int>&Postorder){
        if(node==NULL) return;
        dfs(node->left,Postorder);
        dfs(node->right,Postorder);
        Postorder.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>Postorder;
        dfs(root,Postorder);
        return Postorder;
    }
};