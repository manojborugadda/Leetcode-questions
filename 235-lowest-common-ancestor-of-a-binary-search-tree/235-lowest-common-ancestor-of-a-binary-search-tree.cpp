/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {//TC:O(N) 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){ // if the root is NULL
            return NULL;
        }
        
        //if any one of the two given nodes is equal to Root node is then ROOT is LCA for sure 
        if( root->val == p->val or root->val == q->val ){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);//left-sub-tree mein traverse krna
        TreeNode* right = lowestCommonAncestor(root->right,p,q);//right-sub-tree mein traverse krna
        
        if(left != NULL and right != NULL){//1st condition
            return root;
        }else if(left != NULL){//2nd Condition
            return left;
        }else{//3rd condition
            return right;
        }
     return NULL;
    }
};