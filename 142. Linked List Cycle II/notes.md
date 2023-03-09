```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next==NULL) return NULL;
        ListNode *slow =head;
        ListNode *fast = head;
        ListNode *entry = head;
        while(fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
```

https://www.youtube.com/watch?v=gWv_D_iBQBk
