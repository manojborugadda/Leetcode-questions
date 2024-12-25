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
class Solution {//TC:O(N) where N is the total no of nodes
public:// SC:O(K) where k is the no of nodes in the queue
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()) {
            int size = q.size();
            // auto node = q.front();
            // q.pop();
            int maxi = INT_MIN;
            for(int i =0;i<size;i++) {//we are traversing the whole level using BFS and checking for the MAXIMUM in every level
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                maxi = max(maxi,node->val);
            }
            ans.emplace_back(maxi);
        }
        return ans;
    }
};
