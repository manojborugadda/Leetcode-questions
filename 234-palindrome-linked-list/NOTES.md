https://www.youtube.com/watch?v=3thY0z3Pf5k
​
/// Using STACKS
* traverse the linkedlist and push each value into the stack.
* traverse the list again and pop the elements and compare the poped element with the corresponding linked list element.
* return false if poped_element != list_element , else return true.
​
```
class Solution {
public:
bool isPalindrome(ListNode* head) {
stack<int> s;
ListNode* temp = head;
while(temp!=NULL){
s.push(temp->val);
temp = temp->next;
}
temp = head;
while(temp!=NULL || !s.empty()){
int val = s.top();
s.pop();
if(val!=temp->val) return false;
temp = temp->next;
}
return true;
}
};
```