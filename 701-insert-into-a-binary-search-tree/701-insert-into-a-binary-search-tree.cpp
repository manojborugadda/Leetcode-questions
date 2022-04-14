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
class Solution {  // TC:O(logn)  SC:O(1)
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val); // if the tree is empty we insert the first node
        
        if(root->val < val){ // inserting in the right sub tree
            root->right = insertIntoBST(root->right,val);
            
        }else { // inserting in the left subtree
            root->left = insertIntoBST(root->left,val);
        }
        
        return root;    //      Returning the root node of the BST
    }
};