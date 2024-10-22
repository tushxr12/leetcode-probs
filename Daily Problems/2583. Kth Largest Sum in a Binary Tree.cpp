/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            long long currSum = 0;
            for(int i = 0;i < sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                currSum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            levelSum.push(currSum);
        }
        if(levelSum.size() < k)
            return -1;
        for(int i = 0;i < k - 1;i++)
            levelSum.pop();
        return levelSum.top();
    }
};
