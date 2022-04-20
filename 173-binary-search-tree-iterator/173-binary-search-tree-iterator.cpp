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
class BSTIterator {
public:         //  TC:O(N)            SC:O(1)
    
    // initializing the STACK
    stack<TreeNode*>st;
    TreeNode* current;
    
    BSTIterator(TreeNode* root) {
        current = root;
    }
    
    int next() {
        while(current!=NULL){
            st.push(current);
            current  = current->left;
        }
        TreeNode* temp  = st.top();
        st.pop();
        current = temp->right;
        return temp->val;
    }
    
    bool hasNext() {
        return (current != NULL or st.empty() == false);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */