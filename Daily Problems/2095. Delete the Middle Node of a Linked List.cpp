class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;

        ListNode* slow = head, *fast = head, *prev = NULL;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* toDelete = slow;
        prev->next = slow->next;
        delete(toDelete);
        return head;
    }
};
