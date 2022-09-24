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
class Solution {  //TC:O(N) --- no.of nodes in the tree and SC:O(H) ----height of the Tree
public:
    
    // vector to maintenance the nodes in the current path
    vector<int> path;
    // vector to save all paths that have sum equals to target
    vector< vector<int> > ans;
    
    void dfs(TreeNode* curr, int sum,int target)
    {
        if(!curr)
            return;
        
        sum += curr->val;
        path.push_back(curr->val);
        
        // if curr Node is a leaf
        if(!curr->left && !curr->right)
        {
            if(sum == target)            
                ans.push_back(path);            
        }
        else
        {
            dfs(curr->left,sum,target);
            dfs(curr->right,sum,target);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        ans.clear();
        dfs(root,0,targetSum);
        return ans;
    }
};