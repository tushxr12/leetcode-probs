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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ListNode *newHead = new ListNode(-1);
        ListNode *temp = newHead;
        if (!head)
            return nullptr;
        set<int> st(nums.begin(), nums.end());
        while (head)
        {
            if (st.find(head->val) == st.end())
            {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = nullptr;
        return newHead->next;
    }
};

// Cleaner approach (Nov 1st 2025 Daily Coding problem)
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        while(head!=NULL && st.find(head->val) != st.end())
        {
            ListNode* toDelete = head;
            head = head->next;
        }
        
        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL)
        {
            if(st.find(temp->next->val) != st.end())
            {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete(toDelete);
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};
