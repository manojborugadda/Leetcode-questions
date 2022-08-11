​class Solution { //TC:O(N) as we traverse all the elements in the nums array
                //SC:O(logn) height of the Balance BST
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //inserting the elements into the VECTOR from the List
        vector<int>arr;
        while(head != NULL){
            arr.push_back(head->val);
            head  = head->next;
        }
        
        return convertBST(0,arr.size()-1,arr);
    }
    
    TreeNode* convertBST(int left , int right , vector<int>&nums){
        if(left > right) return NULL; 
        int mid = (left+right)>>1;
        TreeNode* root = new TreeNode( nums[mid] );//creating the ROOT first
        root->left = convertBST(left,mid-1,nums); // recursively creating LEFT and RIGHT subtrees
        root->right = convertBST(mid+1,right,nums);
        return root;
    }
};
