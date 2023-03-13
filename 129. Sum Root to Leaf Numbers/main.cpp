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












 Time Complexity: O(N). Each node is visited once.
 *
 * Space Complexity: O(H). Stack space.
 * In case of balanced tree (best case) it will be O(log N) and in case of Skewed Tree (worst case) it will be O(N)
 *
 * N = Total number of nodes in the tree. H = Height of the tree.
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        return sumNumbersHelper( root,0);
    }

    int sumNumbersHelper(TreeNode* root,int currVal) {
        if(root == NULL ) return 0;
        currVal = currVal*10 + root->val;//sum of the root to LeafNumbers
        if(root->left == NULL and root->right == NULL) return currVal;//if the nodes are leafNodes
        return sumNumbersHelper(root->left,currVal) + sumNumbersHelper(root->right,currVal);
    }
};
