/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
                        // TC:O(N) SC:O(h) , h = height of the binary tree
class Solution {  
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans;
         return inOrder(original,cloned,target,ans);
    }
    
   TreeNode* inOrder(TreeNode* original, TreeNode* cloned, TreeNode* target,TreeNode* &ans){
       
       if(original != NULL){  // here we are using INORDER traversal DFS
           // 
           inOrder(original->left,cloned->left,target,ans);  // left subtree
           
           if(original == target){  // checking the target is equal to the rootnode
               ans = cloned;
           }
           inOrder(original->right,cloned->right,target,ans); // right subree
       }
       return ans;
   }
};