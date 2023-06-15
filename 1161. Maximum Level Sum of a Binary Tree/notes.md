```
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN, level = 1, ans = 1;
        while(!q.empty()){
            int sz = q.size();
            int curSum = 0;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(curSum>maxSum){
                maxSum = curSum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
```
