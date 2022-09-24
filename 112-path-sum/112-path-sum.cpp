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
class Solution { //DFS traversal ------- PREORDER traversal
public:             //TC:O(N) --- no.of nodes in the tree and SC:O(H) ----height of the Tree
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int currSum = 0;
        return DFS(root,currSum,targetSum);
    }
    
    
    bool DFS(TreeNode* node,int currSum,int target) {
        if(node == NULL) return false;
        currSum += node->val; //keeps the current sum Value
        //if we reach the Leaf nodes the we check the condition if the currsum is EQUAL to TARGET
        if(node->left == NULL and node->right == NULL) return currSum == target;
        else{ //if not we traverse in either of LEFT or RIGHT of the current node
         return DFS(node->left,currSum,target) or DFS(node->right,currSum,target) ;   
        }
    }
};