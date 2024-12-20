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
class Solution {//TC:O(N)+K/2 where k is length of Vector
public:          //SC:O(H) height of the treee
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            vector<TreeNode*>temp;
            int size = q.size();
            for(int i =0 ;i<size;i++) {
                auto node = q.front();
                q.pop();
                temp.push_back(node);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }

            if(level % 2 == 1) {//if the level is ODD
                int n = temp.size();
                for(int i =0;i<n/2;i++) {
                    swap(temp[i]->val,temp[n-i-1]->val);//swapping the values
                }
            }
            level++;
        }
        return root;
    }
};
