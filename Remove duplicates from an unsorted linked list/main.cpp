// https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {//TC:O(N) SC:O(N)
  public:
    Node *removeDuplicates(Node *head) {
        Node* prev = NULL,*curr = head;
        unordered_set<int> seen;
        while(curr != NULL) {
            if(seen.count(curr->data)) {//if we find the duplicate element in the SET
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else {
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
