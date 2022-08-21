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
/*
    Time - O(n)
    Space - O(n)
*/
public:
    int ans = 0;
    void buildGraph(TreeNode* root,vector<vector<int>>&adj) {
        if(root == NULL) return;
        
        if(root->left){ // if ROOT's left value is not NULL
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        
        if(root->right){  //if right value of the ROOT is Not NULL
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        
        buildGraph(root->left,adj);
        buildGraph(root->right,adj);
    }
    
    void BFS(int start,vector<vector<int>>&adj,vector<bool>&visited) {
        queue<int>q;
        q.push(start);
        while(q.empty() == false){
            int k=q.size();
            while(k--){
                int u=q.front();
                q.pop();
                visited[u]=1; //marking as 1
                for(int i=0;i<adj[u].size();i++){
                    if(visited[adj[u][i]]==0){ 
                    q.push(adj[u][i]);
                    visited[adj[u][i]]=1;//marking as VISITED as soon as we visit that node
                    }
                }
            }
            //after this loop one BFS is Completed Which means node and its Neighbouring nodes are infected and takes 1 Minute
            ans++;    
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>>adj(100001);
        vector<bool>visited(100001);
        //building the GRAPH
        buildGraph(root,adj);
        ans = 0;
        BFS(start,adj,visited); // BFS traversal for counting the number of Minutes
        return ans-1;
    }
};