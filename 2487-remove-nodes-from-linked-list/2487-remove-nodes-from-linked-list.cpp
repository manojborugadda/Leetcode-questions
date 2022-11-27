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
class Solution { //TC:O(N) SC:O(1)
public:
    /**
    first we have to REVERSE the list and while traversing remove the smaller elements which less than current elements and at last REVERSE again to get correct ordered list according to the problem
    */
    ListNode* removeNodes(ListNode* head) {
        ListNode* tail = reverseList(head);
        ListNode* ptr = tail;
        while(ptr->next != nullptr) {
            if(ptr->next->val < ptr->val) {
                ptr->next = ptr->next->next;
            }else {
                ptr = ptr->next;
            }
        }
        return reverseList(tail);
    }
    
    //method for reversing the linkedList
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *nex;
        while(cur != NULL){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};