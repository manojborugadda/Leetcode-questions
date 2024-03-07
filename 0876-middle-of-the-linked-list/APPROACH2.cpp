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
    int lengthOfList(ListNode *head) {//finding the length of the linkedLIST
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = lengthOfList(head); //length of the LinkedList
        int middle = len/2;
        int count = 0;
        ListNode* temp = head;
        while(count < middle) {
            count++;
            temp = temp->next;
        }
        return temp;
    }
};
