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
class Solution {//TC:O(N)  SC:O(N) --> due to the recursive function calls and the space required for the call stack.
public:
    int diameter = INT_MIN;
    int heightTree(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);
        diameter = max(diameter,leftHeight + rightHeight);
        return max(leftHeight,rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        heightTree(root);
        return diameter;
    } 
    /*
    Calculate height at reach level for each left and right side of tree and compare diameter with the sum of both heights.
    **/
};
