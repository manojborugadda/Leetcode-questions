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
class Solution { //TC:O(N)  SC:O(logn) -- n is the height of the Binary Tree
public:
    bool isValidBST(TreeNode* root) {
       return helper(root,LONG_MIN,LONG_MAX);
    }
    
    bool helper(TreeNode* node,long lower_bound , long higher_bound){
        if(node == NULL) return true;//base condition
        if( (node->val > lower_bound and node->val < higher_bound) == false ) return false;
        return helper(node->left,lower_bound,node->val) and helper(node->right,node->val,higher_bound);
    }
};
