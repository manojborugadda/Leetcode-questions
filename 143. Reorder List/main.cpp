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
class Solution {//TC:O(N)  SC:O(1)
public:
    ListNode* reverse(ListNode* node) {//reversing the linkedList
        ListNode* prev = NULL , *curr = node , *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //finding the middle of the linkedlist
        ListNode* fast = head , *slow = head , *mid = NULL;
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ///-------IMPORTANT Property in LinkedList
        
        // when we traverse all the elements in the using FAST and SLOW Pointers
        // if the FAST does not equals to NULL it means ODD number of elements are
        // present in the LinkedList otherwise EVEN  no.of elements are there
       
        if(fast!=NULL) {/// ODD no.of Elements
            mid = slow->next;
        }else {/// EVEN no.of Elements
            mid = slow;
        }

    // so we got the MID of the LinkedList and we will cut the left PART by traversing until MID element and keeping the next of TEMP as NULL
        ListNode* temp = head;
        while(temp!= NULL and temp->next != mid) {
            temp = temp->next;
        }
        temp->next = NULL;//separating the first and second half


        ListNode* secondHalf = reverse(mid);
        ListNode* firstHalf = head;
        //merging second and first Half
        while(secondHalf != NULL) {
            ListNode*t1 = firstHalf->next;
            ListNode*t2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = t1;

            secondHalf = t2;
            firstHalf = t1;
        }
    }
};

/*
refer the below
  https://leetcode.com/problems/reverse-linked-list/description/

  https://leetcode.com/problems/palindrome-linked-list/description/?envType=daily-question&envId=2024-03-21

***/
