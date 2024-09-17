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
    vector<vector<int>> spiralMatrix(int rows, int cols, ListNode *head)
    {
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        int top = 0, left = 0, right = cols - 1, bottom = rows - 1;

        while (top <= bottom && left <= right)
        {
            // Left to Right
            for (int col = left; col <= right; col++)
            {
                if (head)
                {
                    ans[top][col] = head->val;
                    head = head->next;
                }
            }
            top++;

            // Top to Bottom
            for (int row = top; row <= bottom; row++)
            {
                if (head)
                {
                    ans[row][right] = head->val;
                    head = head->next;
                }
            }
            right--;

            // Right to Left
            for (int col = right; top <= bottom && col >= left; col--)
            {
                if (head)
                {
                    ans[bottom][col] = head->val;
                    head = head->next;
                }
            }
            bottom--;

            // Bottom to Top
            for (int row = bottom; left <= right && row >= top; row--)
            {
                if (head)
                {
                    ans[row][left] = head->val;
                    head = head->next;
                }
            }
            left++;
        }
        return ans;
    }
};