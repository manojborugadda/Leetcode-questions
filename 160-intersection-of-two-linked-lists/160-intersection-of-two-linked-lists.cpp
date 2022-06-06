/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//// TC:O(M+N) where M--> length of the firstList , N-->Length of the secondList
////   SC:O(1)
class Solution {  //In this Approach we dont calculate the Lengths.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        while(A!=B){
            ////////////////
            if(A==NULL){ // if A pointer reaches NULL we point ths A to headB
                A = headB; 
            }else{
                A  = A->next;
            }
            ////////
            if(B==NULL){ // if B pointer reaches NULL we point ths A to headA
                B = headA;
            }else{
                B  = B->next;
            }
        }
        return A; // at last it points to the intersection of Two lists
    }
};