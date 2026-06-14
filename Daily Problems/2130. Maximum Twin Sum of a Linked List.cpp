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
    int pairSum(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0, j = arr.size() - 1;
        int maxSum = 0;
        while(i < j)
        {
            int sum = arr[i++] + arr[j--];
            maxSum = max(maxSum,sum);
        }

        return maxSum;
    }
};

// Optimal
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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* temp = head, *prev = NULL;
        while(temp)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverse = reverseLL(slow->next);
        int maxi = 0;

        ListNode* temp = head;

        while(reverse != NULL)
        {
            maxi = max(maxi, reverse->val + temp->val);
            temp = temp->next;
            reverse = reverse->next;
        }
        return maxi;
    }
};
