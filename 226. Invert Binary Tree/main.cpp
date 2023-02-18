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
class Solution {//TC:O(N)  SC:O(N)  Using BFS approach
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty() == false) {
            TreeNode* curr = q.front();
            q.pop();
            //swapping the left and right nodes
            TreeNode* dummy = curr->left;
            curr->left = curr->right;
            curr->right = dummy;
            //if the current node's left and right are present we push in to the QUEUE
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
        return root;
    }
};
