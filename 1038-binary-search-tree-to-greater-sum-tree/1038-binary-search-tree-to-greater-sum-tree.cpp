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
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
    
    void traverse(TreeNode* root){
        if(root==NULL) return;
        
      traverse(root->right); // first traverse in the right side
      sum = sum+root->val;
      root->val  = sum;
      traverse(root->left);
    }
    
};