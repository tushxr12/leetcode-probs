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
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto qItem = q.front();
            q.pop();

            TreeNode *currNode = qItem.first;
            int level = qItem.second.first;
            int line = qItem.second.second;

            nodes[line][level].insert(currNode->val);
            if (currNode->left)
                q.push({currNode->left, {level + 1, line - 1}});
            if (currNode->right)
                q.push({currNode->right, {level + 1, line + 1}});
        }

        for (auto i : nodes)
        {
            vector<int> col;
            for (auto j : i.second)
            {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};