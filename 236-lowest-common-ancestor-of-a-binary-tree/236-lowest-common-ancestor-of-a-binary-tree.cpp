/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //TC:O(N)
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return NULL;
        }
        
        if( root->val == p->val or root->val == q->val){
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left != NULL and right != NULL){
            return root;
        }else if(left != NULL){
            return left;
        }else{
            return right;
        }
     return NULL;   
    }
};