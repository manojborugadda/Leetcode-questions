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
class Solution {  //TC:O(N)  SC:O(N)  using UNORDERED_MAP 
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>map;
         return solve(root,k,map);
    }
    
    bool solve(TreeNode* root, int k,unordered_map<int,int>&map) {
        if(root == nullptr) return false;
        if(map.find(k- root->val) != map.end()) return true;
        map[root->val]++;
        return solve(root->left , k , map) or solve(root->right , k , map);
    }
};