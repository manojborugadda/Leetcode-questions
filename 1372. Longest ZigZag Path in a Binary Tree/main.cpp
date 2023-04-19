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
class Solution {//TC:O(N+N)  SC:O(N+N)
public:
    int maxLen = 0;
    int longestZigZag(TreeNode* root) {
        recur(root,1,0);
        recur(root,0,0);
        return maxLen;
    }

    void recur(TreeNode* node,int direction,int currLen) {
        if(!node) {
            return;
        }
        maxLen = max(maxLen,currLen);
        if(direction == 1) {
            recur(node->left,0,currLen+1);
            recur(node->right,1,1);
        }else {
             recur(node->right,1,currLen+1);
            recur(node->left,0,1);
        }
    }
};
