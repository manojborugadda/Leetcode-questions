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
    int height(TreeNode *root,int &d)    /// we take the maximum of (heights of right subtree and left subtree
{
    if(root == NULL)
    {
        return -1;
    }
    int Leftree = height(root->left,d);
    int Rightree = height(root->right,d);
    d = max(d, Leftree + Rightree + 2);
    return max(Leftree , Rightree) + 1;
}
    
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        
    int d;
    d = 0;
    height(root,d);
    return d;
        
    }
    
    
};