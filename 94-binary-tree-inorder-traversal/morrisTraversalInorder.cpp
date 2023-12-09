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
class Solution {//TC:O(N)  SC:O(1)
public:
    vector<int> inorderTraversal(TreeNode* root) {//MORRIS TRAVERSAL
    vector<int>ans;
    TreeNode* curr = root;
    while(curr!= nullptr) {
        if(curr->left != nullptr) {
            TreeNode* temp = curr->left;
            TreeNode* leftpointer = curr->left;
            while(temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = curr;
            curr->left = nullptr;
            curr = leftpointer;
        }else{
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
      return ans;
    }
};
