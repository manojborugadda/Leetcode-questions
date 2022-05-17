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
class Solution {  // We solved this problem using  EXTRA SPACE  (MAP)
public:
    //TC:O(N)  N is the number of Nodes and SC:O(N) size of the MAP
    void inorder(TreeNode* root,unordered_map<int,int>&mp){
          if(root==NULL) return;
          inorder(root->left,mp);
          mp[root->val]++;
          inorder(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>mp;
        inorder(root,mp);
        
        int maxi = INT_MIN;
        for(auto x:mp){
            maxi = max(maxi,x.second);
        }
        
        for(auto k:mp){
            if(k.second == maxi){
                ans.push_back(k.first);
            }
        }
        return ans;
    }
};