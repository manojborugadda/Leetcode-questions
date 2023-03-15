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
class Solution {//TC:O(N) SC:O(N)  
public://solved using BFS approach
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return false;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) {//if any childrens are NULL in the queue it is not complete Binary Tree
                flag = true;
            }else {
                q.push(curr->left);
                q.push(curr->right);
                if(flag == true) {
                    return false;
                }
            }
        }
        return true;
    }
};
