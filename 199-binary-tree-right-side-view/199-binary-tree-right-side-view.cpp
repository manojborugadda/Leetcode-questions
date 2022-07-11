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
class Solution {  //TC:O(N)   SC:O(N)
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            int n = q.size();///// number of nodes at current level
            for(int i = 0;i<n;i++){ /// Traverse all nodes of current level
                TreeNode* temp = q.front();
                q.pop();
                if(i==n-1){ //inserting the last element into the answer vector
                    ans.push_back(temp->val);
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};