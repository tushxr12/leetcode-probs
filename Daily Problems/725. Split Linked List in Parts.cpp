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
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k);
        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }

        int divideEqually = len / k;
        int rem = len % k;

        curr = head;

        for (int i = 0; i < k; i++)
        {
            ListNode newPart(0);
            ListNode *tail = &newPart;

            int currSize = divideEqually;
            if (rem > 0)
            {
                rem--;
                currSize++;
            }

            for (int j = 0; j < currSize; j++)
            {
                tail->next = new ListNode(curr->val);
                tail = tail->next;
                curr = curr->next;
            }
            ans[i] = newPart.next;
        }
        return ans;
    }
};