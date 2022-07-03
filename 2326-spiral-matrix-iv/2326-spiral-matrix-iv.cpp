/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Similar to SPIRAL MATRIX II 
// refer that problem before solving this-------------

class Solution {  //TC:O(N^2)  SC:(M*N)
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>>ans(m,vector<int>(n,-1)); // filling the matrix with -1's
        int left = 0 , top = 0 , right = n-1 , bottom = m-1;
        int direction = 1;
        int k;
        while(head!=NULL and left<=right and top<=bottom){
            if(direction == 1){
                for(int i = left;i<=right;i++){
                    if(head != NULL){ // if head is Not EQUAL to NULL we take the value
                          k = head->val;
                        head = head->next;
                    }else{ // if it is NULL we break the loop
                        break;
                    }
                    
                    ans[top][i] = k;
                }
                
                top++;
                direction = 2;
            }
            
            else if(direction == 2){ 
                for(int i = top;i<=bottom;i++){
                    if(head!=NULL){// if head is Not EQUAL to NULL we take the value
                         k = head->val;
                        head = head->next;
                    }else{ // if it is NULL we break the loop
                        break;
                    }
                    
                    ans[i][right] = k;
                }
                
                right--;
                direction = 3;
            }
            
             else if(direction == 3){ 
                for(int i = right;i>=left;i--){
                    if(head!=NULL){// if head is Not EQUAL to NULL we take the value
                         k = head->val;
                        head = head->next;
                    }else{ // if it is NULL we break the loop
                        break;
                    }
                    ans[bottom][i] = k;
                }
                
                bottom--;
                direction = 4;
            }
            
            else if(direction == 4){ 
                for(int i = bottom;i>=top;i--){
                    if(head!=NULL){// if head is Not EQUAL to NULL we take the value
                         k = head->val;
                        head = head->next;
                    }else{ // if it is NULL we break the loop
                        break;
                    }
                    
                    ans[i][left] = k;
                }
                
                left++;
                direction = 1;
            }
        }
        return ans;  // returning the matrix
    }
};