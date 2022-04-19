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
    
    int left_count = 0 , right_count = 0;
    
    int countNode(TreeNode* root,int x){
        
        if(root==NULL) return 0; // if tree is empty
        
        int left  = countNode(root->left,x); // 6 in this example
        int right = countNode(root->right,x); // 7  in this example
        
        if(root->val == x){ // if it is equal to x i.e 3 
            left_count = left;
            right_count = right;
        }
        return left+right+1;  // total number of nodes related to 3 here [3,6,7] would come
      
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        left_count = 0 , right_count = 0;
        
        countNode(root,x);
        // counting the nodes except "x" and its related subtrees
        // here in this example [1,2,4,8,9,5,10,11] would come
        int no_nodes_except_x = n - (left_count+right_count+1);
        
        int maxcount = max( no_nodes_except_x , max(left_count,right_count) );
        
        if(maxcount > (n/2)){
            return true;
        }
        else
            return false;
        
    }
};