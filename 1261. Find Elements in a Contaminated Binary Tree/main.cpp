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

 //              time complexity of the total program --- O(n⋅logn+q⋅logn)
 
class FindElements {//TC:O(n logn ) -- insering values into the SET + O( k logn)
public:
    set<int>st;
    void DFS(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            root->left->val = root->val*2 + 1;
            st.insert(root->left->val);
            DFS(root->left);
        }
        if(root->right) {
            root->right->val = root->val*2 + 2;
            st.insert(root->right->val);
            DFS(root->right); 
        }
    }   
    FindElements(TreeNode* root) {//TC;O( K * nlogn)
        root->val = 0;
        st.insert(0);
        DFS(root);
    }
    
    bool find(int target) { // if N queries are there TC:O(N logn)
        if(st.find(target) != st.end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
