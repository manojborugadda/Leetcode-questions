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
class Solution {//TC:O(N)  SC:O(H) where H is the height of the Binary Tree
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        bool reverseCheck = false; //check variable for ZIG ZAG 
        q.push(root);
        while(q.empty()==false) {
            int size = q.size();
            vector<int>level;
            for(int i = 0 ; i < size ; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            if(reverseCheck) {
                reverse(begin(level),end(level));
            }
            ans.push_back(level);
            reverseCheck = !reverseCheck;
        }
        return ans;   
    }
};
