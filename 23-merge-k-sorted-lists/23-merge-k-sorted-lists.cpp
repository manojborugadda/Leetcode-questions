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
    
    struct mycmp{      // we are checking for min heap--------
        bool operator() (ListNode* a,ListNode* b){
            return a->val  > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
            priority_queue<ListNode* ,vector<ListNode*>,mycmp > q;
        // by default it is MAX HEAP so we are converting by adding COMPARATOR  function "mycmp" so it works as MIN HEAP
        
        for(ListNode* x : lists){
                if(x) q.push(x);
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(q.empty()== false){
            
            ListNode*x = q.top();
            q.pop();
            
            //check if the head is null or not
		if(head == NULL)
		{
            head = x;
            tail = x;
        }
		
		//if head is not null
        else{
		  //head will remain the same and tail will iterate to the next node
            tail -> next = x;
            tail = x;
        }
        
		//if x is not null, push the next element of x in the priority queue
        if(x->next) 
		{
			q.push(x->next);
		}
            
    }
        
         return head;   
    }
};