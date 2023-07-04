https://www.youtube.com/watch?v=4wPlA_InnGY
​
```
//TC:O(N) solution , it just traversing all nodes and counting
class Solution {
public: 
int count = 0;
void helper(TreeNode* root){
if(root)
count++;
if(root->left)
helper(root->left);
if(root->right)
helper(root->right);
}
int countNodes(TreeNode* root) {
if(!root)
return 0;
helper(root); 
return count;
}
};
```
