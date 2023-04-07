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
class Solution {  // TC:O(N)  SC:O(N) 
public: 
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root,root);
    }
private:
    bool isMirror(TreeNode* root1,TreeNode* root2) {
        if(root1 == NULL and root2 == NULL) return true;
        if(root1 == NULL or root2 == nullptr) return false;
        return (root1->val == root2->val) and 
            isMirror(root1->left,root2->right) and 
            isMirror(root1->right,root2->left) ;
    }
    
    //the catch of the probem is we have to check subtrees if they are mirrors to each others
};
  
