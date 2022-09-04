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
    //CUSTOM comparator function for Sorting purpose
    static bool comparator(pair<int,int>&a,pair<int,int>&b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>>ans;
        queue<pair<int,pair<TreeNode*,int>>>q;
        unordered_map<int,vector<pair<TreeNode*,int>>>mp;
        q.push({0,{root,0}});
        int mini = 0 , maxi = 0;
        while(q.empty()==false){
            auto p = q.front();
            q.pop();
            mp[p.first].push_back({p.second.first,p.second.second});
            mini = min(mini,p.first);//here we compare the "mini" with distance from centre of the TREE
            maxi = max(maxi,p.first);
            if(p.second.first->left){
                q.push({p.first-1,{p.second.first->left,p.second.second+1}});
            }
            if(p.second.first->right){
                q.push({p.first+1,{p.second.first->right,p.second.second+1}});
            } 
        }
        
        for(int i = mini;i<=maxi;i++){
            vector<pair<int,int>>temp;
            vector<int>vect;
            for(auto x : mp[i]){
                temp.push_back({x.first->val,x.second});
//In such a case multiple nodes in the same row and same column, sort these nodes by their values.
                sort(begin(temp),end(temp),comparator);
            }
            
            for(auto x:temp){
                vect.push_back(x.first);
            }
            
            ans.push_back(vect);
        }
        
        return ans;
    }
};