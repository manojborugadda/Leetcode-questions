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
class Solution {//TC:O(N)  SC;O(N)
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum=0;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        unordered_map<int,ListNode*>mp;
        mp[0]=dummyNode;

        while(head!=NULL){
            prefixSum+= head->val;
            if(mp.find(prefixSum)!= mp.end()){
                //delete work
                
                ListNode* start=mp[prefixSum];
                ListNode* temp=start;
                int prefix= prefixSum;
                while(temp!=head){
                    temp= temp->next;
                    prefix += temp->val;
                    if(temp!=head){
                        mp.erase(prefix);
                    } 
                }
                start->next= head->next;

            }
            else{
                mp[prefixSum]= head;

            }
            head=head->next;
        }
        return dummyNode->next;
    }
};
