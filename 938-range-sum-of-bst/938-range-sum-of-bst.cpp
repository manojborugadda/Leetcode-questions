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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root== NULL) return 0;  // if tree is empty
        
        // if the root value lies in the Range
        if(root->val <= high and root->val >= low)
        {
          return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
        
        // if the root value is less than left node we traverse in the RIGHT subtree
        else if(root->val < low){
           return rangeSumBST(root->right,low,high);
        }
        else{ // if the root value is less than right node we traverse in the LEFT subtree
          return  rangeSumBST(root->left,low,high);
        } 
    }
};