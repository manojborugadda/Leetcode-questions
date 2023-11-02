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
class Solution {//TC:O(N)  Space complexity:O(1), No extra space is used , except for recursive stack space
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        findAvgOfSubTree(root , count);
        return count;
    }

    pair<int,int>findAvgOfSubTree(TreeNode* root , int &count) {
        if(!root) {
            return {0,0};
        }

        auto leftPair = findAvgOfSubTree(root->left , count);
        auto rightPair = findAvgOfSubTree(root->right , count);

        int totalsum = leftPair.first + rightPair.first + root->val;
        int totalCount = leftPair.second + rightPair.second + 1;// 1 is for the current node
        int avg = totalsum/totalCount;
        if(avg == root->val ) {
            count++;
        }
        return {totalsum , totalCount};
    }
};
