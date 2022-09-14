
class Solution { //TC = O(N*constant)
public:



    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10,0);
        int count = 0;
        dfs(root,freq,count);
        return count;
    }
    
    void dfs(TreeNode* root , vector<int>freq , int &count) {
        if(root == NULL) return;
        freq[root->val]++;
        dfs(root->left,freq,count);
        if(root->left == NULL and root->right == NULL) {//if we reach the LEAF Nodes
             int oddCount = 0;
        //then we will count the number of elements whose occurence is odd
            for(auto x:freq){
                if(x%2 == 1){
                    oddCount++; //if oddCount of such elements is <=1, then we update count
                }
            }
/*
For eg, 2->3->3 is a path so in map, occurences of 2=1 and 3=2
In order to obatain a palindrome, there should be a single element present whose count of occurences is odd.Hence, 2->3->3 is a plaindrome since it can be arranged to 3->2->3
*/


            if(oddCount <= 1) count++;
            
        }
          dfs(root->right,freq,count);
    }
};
