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
    // Keep track of sum at every level and reset it to ZERO if next level is present.
   // At last level return sum.
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty()==false)
        {
            int n = q.size();
            
            for(int i = 0;i<n;i++){
                
                TreeNode* temp = q.front();
                q.pop();
                sum = sum+temp->val;
                
                if(temp->left){  // pushing the left child if present
                    q.push(temp->left);
                }
                if(temp->right){  // pushing the right child if present
                    q.push(temp->right);
                }
            }
            
            if(q.empty()==false){ //if queue is not empty it means more levels are present below
                sum = 0;
            }
        }
        
        return sum;
    }
}; 