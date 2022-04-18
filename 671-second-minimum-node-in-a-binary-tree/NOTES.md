class Solution {
public:
set<int> set;
int findSecondMinimumValue(TreeNode* root) {
dfs(root);
int count=0;
for(auto it:set){
if(count==1)
return it;
count++;
}
return -1;
}
void dfs(TreeNode* root){
if(root){
dfs(root->left);
set.insert(root->val);
dfs(root->right);
}
}
};