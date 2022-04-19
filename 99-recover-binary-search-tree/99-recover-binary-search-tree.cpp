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
class Solution { // here we are following modified INORDER travsersal
public:
     TreeNode *prev , *first , *second; 
    
    void inorder(TreeNode* root){
        
        if(root==NULL) return;  // base case
        
        // left sub tree
        inorder(root->left);
        
        //giving the logic here for getting first and second
        if(!first and root->val < prev->val){
            first = prev;
        }
        if(first and root->val < prev->val){
            second = root;
        }
        prev = root;
        
        // right subtree
        inorder(root->right);
    }
   
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val , second->val);
    }
};