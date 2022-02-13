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
    vector<int> ans;
    void traverse(TreeNode* root, int level){
        if(root==NULL) return ;
        if(level < ans.size()){
            if(root->val > ans[level]){
                ans[level] = root->val;
            }
        }
        else
        {
            ans.push_back(root->val);
        }
             traverse(root->left,level+1);
            traverse(root->right,level+1);
    }
        vector<int> largestValues(TreeNode* root) {
        traverse(root,0);
            return ans;
        }
};