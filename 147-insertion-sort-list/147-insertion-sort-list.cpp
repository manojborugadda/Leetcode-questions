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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode*dummyHead = new ListNode(-5001);
        
        // pointer for finding the node which is out of sort sync
        ListNode* toInsert;
        
        //pointer for preInsert
        ListNode* preInsert;
        
        dummyHead->next = head;
        
        ListNode*curr = head; //current pointer
        
        //traversing for the node which is violating the sorting order
        while(curr != NULL and curr->next != NULL){
            if(curr->val <= curr->next->val){
                curr = curr->next;
            }else{
                toInsert = curr->next; //this node is violating the SORT order
                curr->next = toInsert->next;//pointing the curr next to the next of toInsert
                //pointing the preInsert pointer to DummyHead 
                preInsert = dummyHead;
//traversing for knowing the location so that we can point toInsert next to preInsert next
                while(preInsert->next->val < toInsert->val){
                    preInsert = preInsert->next;
                }
                toInsert->next = preInsert->next;
                preInsert->next   = toInsert;
            }
        }
        return dummyHead->next; //which is actually head;
        
    }
};