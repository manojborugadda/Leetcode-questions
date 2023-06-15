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
class Solution {//TC:O(N)  SC:O(1)
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN , ans = 1;
        if(root==NULL) return ans;
        int level = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            for(int i =0;i<size;i++) {
                TreeNode* a = q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                sum += a->val;
            }
            if(sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
