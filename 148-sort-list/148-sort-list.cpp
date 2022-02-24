class Solution
{
public:
    // Helper function to find the mid of the linked list using standard Tortoise-Hair Method
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge the two sorted Linked List
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        // Creating a new Linked List with a dummy node as -1, in which, we will store our answer linked List;
        ListNode *ans = new ListNode(-1);
        // Node pointing to our dummy node so than we can append elements after it.
        ListNode *temp = ans;

        // Merge 2 sorted Linked lists
        // Iterative Approach
        while (left != NULL && right != NULL)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                {
                    temp->next = right;
                    temp = right;
                    right = right->next;
                }
            }
        }

        // Finally adding the unmerged elements
        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        // Move answer ahead by one point, from our dummy node
        ans = ans->next;
        return ans;
    }

    ListNode *sortList(ListNode *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
            return head;

        // Break linked list into two halves,after finding mid
        ListNode *mid = findMid(head);

        ListNode *left = head;
        ListNode *right = mid->next;
        // To make the last Node of first linked list as NULL
        mid->next = NULL;

        // Calling recursively on left and right havles for merge sorting
        left = sortList(left);
        right = sortList(right);

        // merge both left and right halves(Same as merging two sorted linked list)
        ListNode *result = merge(left, right);

        return result;
    }
};