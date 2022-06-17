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
    //Time Complexity : O(n), 
    //Space Complexity : O(h) [n = number of nodes, h = height of the tree]


public:
    public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 1) res++;
        return res;
    }
    
    /*

The dfs helper functions has three options:
-1 : If we are already covered by a camera
0 : we have a camera
1 : we need a camera

*/
    
private:
    int res = 0;
    
    int dfs(TreeNode* root) {
        if (root==NULL) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == 1 or right == 1) {
            res++;
            return -1;
        }
        else if (left == -1 or right == -1){
            return 0;
        }
        else{
          return 1;   
        }
    }
};