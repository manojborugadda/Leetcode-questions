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
    TreeNode* pruneTree(TreeNode* root) {
        // here we use POST ORDER traversal
        //LEFT RIGHT NODE
        if(root == NULL) return NULL;
        if(root!= NULL){
            root->left = pruneTree(root->left); // left traversal
            root->right = pruneTree(root->right);//right traversal
            //return NULL if the Node value(which is leaf node) is 0 
            if(root->val == 0 and root->left == NULL and root->right == NULL){
                return NULL;
            }
        }
        return root;
    }
};