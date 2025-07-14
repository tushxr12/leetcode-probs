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
private:
    int convert(string s)
    {
        int n = s.size();
        int ans = 0;
        int k = 0;
        for(int i = n - 1;i >= 0;i--)
        {
            if(s[i] == '1')
            {
                ans += pow(2,k);
            }
            k++;
        }
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        string s = "";

        if(!head)
            return 0;

        ListNode* temp = head;
        
        while(temp != nullptr)
        {
            s += to_string(temp->val);
            temp = temp->next;
        }

        int ans = convert(s);
        return ans;
    }
};
