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
class Solution { // INORDER traversal usage is done in this problem
public:
    
    int count;
    set<int>s; // because duplicate elements are there in the input Tree
    
    int findSecondMinimumValue(TreeNode* root) {
         helper(root);
        
        // traversing through the SET for the Second Minimum Element
        for(auto &i : s){
            
         if(count == 1){ /// we are checkin for the 1 index because of the 0 index starting
                return i;
            }
            
            count++;
        }
        return -1; //If no such second minimum value exists, output -1 instead.
    }
    
    void helper(TreeNode* root){
        if(root==NULL) return ;
            
        ///left side traversing
        helper(root->left);
        
        
       //pushing elements into the SET
        s.insert(root->val);
        
        // right side traversing
        helper(root->right);
        
        return;
    }
};