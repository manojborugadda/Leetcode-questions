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
class Solution {// the sum of a subtree the answer is max( (total_sum - subtree_sum) * subtree_sum) in each node.
public:
    int maxProduct(TreeNode* root) {
        long int sum = totalSum(root);
        long int ans = 0;
        MAXIMUM_PROD(root,sum,ans);
        return ans % ((int)pow(10, 9) + 7);
    }

    int totalSum(TreeNode* root) {
        if(root == NULL) return 0;
        return totalSum(root->left) + totalSum(root->right) + root->val;
    }

   int MAXIMUM_PROD(TreeNode* root,long int sum,long int &ans) {//here "ans" is having pass-by-reference,which means it will be updated for every iteration
    if(!root) return 0;
    long int sumOfSubtree = 0;
    sumOfSubtree += MAXIMUM_PROD(root->left,sum,ans);
    sumOfSubtree += MAXIMUM_PROD(root->right,sum,ans);
    sumOfSubtree += root->val;
    if( sumOfSubtree *(sum - sumOfSubtree) > ans) {
        ans = sumOfSubtree *(sum - sumOfSubtree);
    }
        return sumOfSubtree;
    }
};

//we find the subtree sum for all the "Nodes" in the TREE and see for every node if the PRODUCT of sum of BOTH of the splitted trees is MAXIMUM or NOT
