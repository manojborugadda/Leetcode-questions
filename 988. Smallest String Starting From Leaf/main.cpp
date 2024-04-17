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
class Solution {//TC:O(N)  SC:O(N)
public:
    void dfs(TreeNode* root, string &ans,string path) {
        if(!root) return;
        path += ('a'+root->val);
        if(root->left==NULL and root->right==NULL) {
            string temp = path;
            reverse(begin(temp),end(temp));
            if(ans.empty() or temp < ans) {
                ans = temp;
            }
        }
        dfs(root->left,ans,path);
        dfs(root->right,ans,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans,path;
        dfs(root,ans,path);
        return ans;
    }
};
