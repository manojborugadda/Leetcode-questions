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
class Solution {//tc:o(n) sc:o(1)
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(nums.begin(),nums.end());
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* prev = temp;
        while(head != nullptr) {
            if(st.find(head->val)!= st.end()){
                //if we found in the nums array
                head = head->next;
                prev->next = head;
            }else {
                prev = head;
                head = head->next; 
            }
        }
        return temp->next;
    }
};
