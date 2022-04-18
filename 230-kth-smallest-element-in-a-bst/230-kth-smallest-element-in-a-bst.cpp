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
class Solution { /// here we are using the modified IN-ORDER traversal
public:             // TC:O(N) 
                    // SC:O(logN) height of the tree
    
        int count = 0;
        int ans = 0;
    
    int kthSmallest(TreeNode* root, int k) {
        count = k;  // count has copy of k
        helper(root);
        return ans;
    }
    
    void helper(TreeNode* root){
        if(root==NULL) return ;
        
        ///left side traversing
        helper(root->left);
        
        
        // root-val
        count--;
        if(count == 0){
            ans = root->val;
            return;
        }
        
        // right side traversing
        helper(root->right);
        
        return;
    }
};