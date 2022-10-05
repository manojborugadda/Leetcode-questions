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
class Solution {  //TC:O(N)  S:O(N)    //RECURSIVE solution
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return NULL;
        if(depth == 1){
          TreeNode* node =  new TreeNode(val); 
            node->left = root;
            return node;
        } 
         insert(root,val,depth,1);
         return root;
        }
    
void insert(TreeNode* node,int val,int depth,int currDepth) {
    if(node == NULL) return;
    if(currDepth == depth - 1) {//if the currDepth is equal to given depth - 1 we ADD ONE row to the tree
        //inserting left nodes with given "val"
        TreeNode* temp = node->left;
        node->left = new TreeNode(val);
        node->left->left = temp;
        //inserting right nodes with given 'val'
        temp = node->right;
        node->right = new TreeNode(val);
        node->right->right = temp;
    }else {
        insert(node->left,val,depth,currDepth+1);
        insert(node->right,val,depth,currDepth+1);
    }
}

};