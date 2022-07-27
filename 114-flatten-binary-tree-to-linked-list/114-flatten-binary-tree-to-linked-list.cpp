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
class Solution { //TC:O(N)   SC:O(N)----------using STACK
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*>s;
        
        s.push(root);
        
        while(s.empty()==false){
            
            TreeNode* curr = s.top();
            s.pop();
            
             if(curr->right != NULL){ //inserting the RIGHT node
                s.push(curr->right);
            }
            
            if(curr->left != NULL){ //pushing the LEFT node
                s.push(curr->left);
            }
            
            if(s.empty() == false){  //if stack is NOT empty we connect the curr to TOP element
                curr->right = s.top();
            }
            curr->left = NULL;//updates the left of curr to NULL
        }
    }
};

