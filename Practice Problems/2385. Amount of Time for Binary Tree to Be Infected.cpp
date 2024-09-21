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
private:
    TreeNode *mapParents(TreeNode *root, map<TreeNode *, TreeNode *> &parentMap, int start)
    {
        if (!root)
            return nullptr;

        TreeNode *toReturn = new TreeNode(-1);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode->val == start)
                toReturn = currNode;
            if (currNode->left)
            {
                q.push(currNode->left);
                parentMap[currNode->left] = currNode;
            }

            if (currNode->right)
            {
                q.push(currNode->right);
                parentMap[currNode->right] = currNode;
            }
        }
        return toReturn;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        int ans = 0;
        map<TreeNode *, TreeNode *> parentMap;
        TreeNode *startNode = mapParents(root, parentMap, start);

        map<TreeNode *, bool> visited;
        visited[startNode] = true;
        queue<TreeNode *> q;
        q.push(startNode);

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                if (currNode->left && !visited[currNode->left])
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                    flag = true;
                }

                if (currNode->right && !visited[currNode->right])
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                    flag = true;
                }

                if (parentMap[currNode] && !visited[parentMap[currNode]])
                {
                    q.push(parentMap[currNode]);
                    visited[parentMap[currNode]] = true;
                    flag = true;
                }
            }
            if (flag)
                ans++;
        }

        return ans;
    }
};