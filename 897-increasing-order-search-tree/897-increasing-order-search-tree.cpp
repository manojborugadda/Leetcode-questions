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
    
    TreeNode * head = new TreeNode(0); // it is used to traverse
    TreeNode * ptr = head; // which points to the head
       
    TreeNode* increasingBST(TreeNode* root) {
      helper(root);
        return ptr->right;
    }
    
        void helper(TreeNode *root){ 
        if(root==NULL) return ;
        helper(root->left);
        head->right  = new TreeNode(root->val);
        head = head->right;
        helper(root->right);
    }
    
};