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

// Idea behind approach is:
// 1) Use indexing like in Segment Trees.
// 2) Take care of overflow (eg: skew trees) - start indexing at every level from 1 index

class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;    // {node, distance}
        q.push({root, 1});  // 1 indexing of seg-tree
        
        while(!q.empty()){
            int sz = (int)q.size();
            long long subtract = q.front().second;    // To make the idx start from 1 on every level
            long long mn, mx;
            
            for(int i = 0; i < sz; i++){
                long long cur_idx = q.front().second - subtract + 1;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0) mn = cur_idx;
                if(i == sz - 1) mx = cur_idx;
                
                if(node->left != NULL)
                    q.push({node->left, 2* cur_idx});
                if(node->right != NULL)
                    q.push({node->right, 2* cur_idx + 1});
            }
            ans = max(ans, mx - mn + 1);
        }
        return ans;
    }
};