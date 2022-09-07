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
class Solution {// constructing a string consisting of parenthesis and integers from a binary tree with the PREORDER traversal way
public:
    string tree2str(TreeNode* root) {  //TC:O(N)  SC:O(H)
        if(root == NULL) return "";
        string str;
        ///NODE value-----------------------in PREORDER-----------------
        str = str+to_string(root->val);
        
        //LEFT NODE value--------------------In PREODER-----------
        if(root->left != NULL){//if LEFT node is not NULL
            str += "("+tree2str(root->left)+")";
            //main condition for this problem
        }else if(root->right != NULL){ //means if LEFT node is NULL and RIGHT node is NOT NULL
            str += "()";
        }
        /////RIGHT NODE value--------------------In PREORDER------------
        if(root->right != NULL){
            str +=  "("+tree2str(root->right)+")";
        }
        
        return str;//returning the Answer string
    }
};